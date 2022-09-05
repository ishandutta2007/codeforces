#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,popcnt,fma4,lzcnt,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
  int t;
  in >> t;
  for (int i = 0; i < t; i++) {
    int64_t n, m, x0, y0, x1, y1;
    in >> n >> m >> x0 >> y0 >> x1 >> y1;
    int64_t dx = std::abs(x1 - x0);
    int64_t dy = std::abs(y1 - y0);
    int64_t res = n * m - 2 * (n - dx) * (m - dy);
    if (n > 2 * dx && m > 2 * dy) {
      res += (n - 2 * dx) * (m - 2 * dy);
    }
    out << res << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}