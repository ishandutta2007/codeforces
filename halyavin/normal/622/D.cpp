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
  int n;
  in >> n;
  if (n % 2 == 0) {
    int half = n / 2;
    for (int i = 0; i < half; i++) {
      out << (2 *i + 1) << " ";
    }
    for (int i = half - 1; i >= 0; i--) {
      out << (2 * i + 1) << " ";
    }
    for (int i = 1; i < half; i++) {
      out << 2 * i << " ";
    }
    out << n << " ";
    for (int i = half - 1; i >= 1; i--) {
      out << 2 * i << " ";
    }
    out << n << std::endl;
  } else {
    int half = n / 2;
    for (int i = 0; i < half; i++) {
      out << (2 * i + 1) << " ";
    }
    out << n << " ";
    for (int i = half - 1; i>= 0; i--) {
      out << (2 * i + 1) << " ";
    }

    for (int i = 1; i <= half; i++) {
      out << (2 * i) << " ";
    }
    for (int i = half; i>=1; i--) {
      out << (2 * i) << " ";
    }
    out << n << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}