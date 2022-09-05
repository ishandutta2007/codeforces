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

int64_t f(int64_t n) {
  int64_t res = 0;
  for (int64_t i = 2; i * i * i <= n; i++) {
    res += n / (i * i * i);
  }
  return res;
}

void run(std::istream& in, std::ostream& out) {
  int64_t m;
  in >> m;
  int64_t left = 0;
  int64_t right = 8 * m;
  while (right - left > 1) {
    int64_t middle = (left + right) / 2;
    if (f(middle) >= m) {
      right = middle;
    } else {
      left = middle;
    }
  }
  if (f(right) == m) {
    out << right << std::endl;
  } else {
    out << -1 << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}