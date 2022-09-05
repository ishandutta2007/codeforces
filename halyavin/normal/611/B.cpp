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
  uint64_t a, b;
  in >> a >> b;
  int ans = 0;
  for (uint64_t i = 2; i <= 63; i++) {
    for (uint64_t j = 0; j < i - 1; j++) {
      uint64_t num = (uint64_t(1) << i) - (uint64_t(1) << j) - 1;
      if (num >= a && num <= b) {
        ans++;
      }
    }
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}