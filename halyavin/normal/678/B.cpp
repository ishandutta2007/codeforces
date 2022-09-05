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

int days(int year) {
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
    return 2;
  }
  return 1;
}

void run(std::istream &in, std::ostream &out) {
  int y;
  in >> y;
  int res = 0;
  int ydays = days(y);
  for (int i = y;; i++) {
    res = (res + days(i)) % 7;
    if (res == 0 && days(i + 1) == ydays) {
      out << i + 1 << std::endl;
      return;
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}