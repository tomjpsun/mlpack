/**
 * @file binding_info.hpp
 * @author Ryan Curtin
 *
 * This file defines the BindingInfo singleton class that is used specifically
 * for the Markdown bindings to map from a binding name (i.e. "knn") to
 * multiple ProgramDoc objects, which are then used to generate the
 * documentation.
 *
 * mlpack is free software; you may redistribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef MLPACK_BINDINGS_MARKDOWN_BINDING_NAME_HPP
#define MLPACK_BINDINGS_MARKDOWN_BINDING_NAME_HPP

#include <mlpack/prereqs.hpp>
#include <mlpack/core/util/program_doc.hpp>

namespace mlpack {
namespace bindings {
namespace markdown {

/**
 * The BindingInfo class is used by the Markdown documentation generator to
 * store multiple ProgramDoc objects, indexed by both the binding name (i.e.
 * "knn") and the language (i.e. "cli").
 */
class BindingInfo
{
 public:
  //! Return a ProgramDoc object for a given bindingName.
  static util::ProgramDoc& GetProgramDoc(const std::string& bindingName);

  //! Register a ProgramDoc object with the given bindingName.
  static void RegisterProgramDoc(const std::string& bindingName,
                                 const util::ProgramDoc& programDoc);

  //! Get or modify the current language (don't set it to something invalid!).
  static std::string& Language();

 private:
  //! Private constructor, so that only one instance can be created.
  BindingInfo() { }

  //! Get the singleton.
  static BindingInfo& GetSingleton();

  //! Internally-held map for mapping a binding name to a ProgramDoc name.
  std::unordered_map<std::string, util::ProgramDoc> map;

  //! Holds the name of the language that we are currently printing.  This is
  //! modified before printing the documentation, and then used by
  //! print_doc_functions.hpp during printing to print the correct language.
  std::string language;
};

} // namespace markdown
} // namespace bindings
} // namespace mlpack

#endif
