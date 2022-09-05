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
  int64_t n, k;
  in >> n >> k;
  if (k > 1000000) {
    out << -1 << std::endl;
    return;
  }
  int64_t minV = k * (k + 1) / 2;
  int64_t opt = -1;
  for (int64_t i = 1; i * i <= n; i++) {
    if (n % i != 0) {
      continue;
    }
    if (n / i >= minV) {
      opt = std::max(opt, i);
    }
    if (i >= minV) {
      opt = std::max(opt, n / i);
    }
  }
  if (opt == -1) {
    out << -1 << std::endl;
    return;
  }
  int64_t last = k + (n / opt) - minV;
  for (int i = 0; i < k - 1; i++) {
    out << (i + 1) * opt << " ";
  }
  out << last * opt << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}