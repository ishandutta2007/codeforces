#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
  std::string a;
  std::string b;
  in >> a >> b;
  size_t idx;
  for (idx = 0; idx < a.length() - 1; idx++) {
    if (a[idx] != '0') break;
  }
  a = a.substr(idx);
  for (idx = 0; idx < b.length() - 1; idx++) {
    if (b[idx] != '0') break;
  }
  b = b.substr(idx);
  if (a.length() < b.length()) {
    out << "<" << std::endl;
    return;
  }
  if (a.length() > b.length()) {
    out << ">" << std::endl;
    return;
  }
  if (a < b) {
    out << "<" << std::endl;
    return;
  }
  if (a > b) {
    out << ">" << std::endl;
    return;
  }
  out << "=" << std::endl;
  return;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}