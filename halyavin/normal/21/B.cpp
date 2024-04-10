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
  int a1, b1, c1;
  int a2, b2, c2;
  in >> a1 >> b1 >> c1;
  in >> a2 >> b2 >> c2;
  if (a1 == 0 && b1 == 0 && c1 != 0) {
    out << "0" << std::endl;
    return;
  }
  if (a2 == 0 && b2 == 0 && c2 != 0) {
    out << "0" << std::endl;
    return;
  }
  if (a1 == 0 && b1 == 0 && c1 == 0) {
    out << "-1" << std::endl;
    return;
  }
  if (a2 == 0 && b2 == 0 && c2 == 0) {
    out << "-1" << std::endl;
    return;
  }
  if (a1 * b2 == b1 * a2) {
    if (a1 * c2 == a2 * c1 && b1 * c2 == b2 * c1) {
      out << "-1" << std::endl;
    } else {
      out << "0" << std::endl;
    }
  } else {
    out << "1" << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}