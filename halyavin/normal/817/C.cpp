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
  int64_t s, n;
  in >> n >> s;
  if (n < s) {
    out << 0 << std::endl;
    return;
  }
  int64_t res = std::max(int64_t(0), n - (s + 180));
  for (int64_t i = s; i <= s + 180 && i <= n; i++) {
    int64_t copyI = i;
    int64_t sum = 0;
    while (copyI > 0) {
      sum += copyI % 10;
      copyI /= 10;
    }
    if (i - sum >= s) {
      res++;
    }
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}