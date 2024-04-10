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
  int n, d, m, l;
  in >> n >> d >> m >> l;
  int p = 0;
  int i = 0;
  while (true) {
    if (p > l || i >= n) {
      out << (int64_t(i) * m + p) << std::endl;
      return;
    }
    int k = (l - p) / d;
    p += (k + 1) * d;
    i += p / m;
    p = p % m;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}