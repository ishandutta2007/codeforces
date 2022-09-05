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

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::vector<std::vector<double>> m(n, std::vector<double>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      in >> m[i][j];
    }
  }
  std::vector<std::vector<double>> dyn(1 << n, std::vector<double>(n));
  for (uint32_t mask = 1; mask < 1 << n; mask++) {
    uint32_t bits = __builtin_popcount(mask);
    if (bits == 1) {
      dyn[mask][__builtin_ctz(mask)] = 1.0;
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        double p = 0;
        for (int j = 0; j < n; j++) {
          if (mask & (1 << j)) {
            p += m[j][i];
          }
        }
        p /= (bits - 1) * bits / 2;
        for (int j = 0; j < n; j++) {
          dyn[mask][j] += p * dyn[mask - (1 << i)][j];
        }
      }
    }
  }
  out.precision(10);
  for (int i = 0; i < n; i++) {
    out << dyn[(1 << n) - 1][i] << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}