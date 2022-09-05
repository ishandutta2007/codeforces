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
  int64_t x, y;
  in >> x >> y;
  int64_t res = (x / 5) * (y / 5) * 5;
  res += (x/5) * (y % 5);
  res += (y / 5) * (x % 5);
  for (int i = 1; i <= x % 5; i++) {
    for (int j = 1; j <= y % 5; j++) {
      if ((i + j) % 5 == 0) {
        res++;
      }
    }
  }
  out << res << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}