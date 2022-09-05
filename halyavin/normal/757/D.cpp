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

const uint32_t mod = 1000000007;

inline void add(uint32_t& x, uint32_t y) {
  x += y;
  if (x >= mod) x -= mod;
}

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::string s;
  in >> s;
  std::vector<std::vector<uint32_t>> dyn(n + 1, std::vector<uint32_t>(1 << 20));
  dyn[0][0] = 1;
  uint32_t res = 0;
  for (int i = 1; i <= n; i++) {
    int num = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (s[j] == '1') {
        if (i - j > 6) {
          break;
        }
        num += 1 << (i - j - 1);
      }
      if (num > 20) break;
      if (num == 0) continue;
      int mask = 1 << (num - 1);
      for (int k = 0; k < 1 << 20; k++) {
        add(dyn[i][k | mask], dyn[j][k]);
      }
    }
    for (int j = 1; j <= 20; j++) {
      add(res, dyn[i][(1 << j) - 1]);
    }
    add(dyn[i][0], 1);
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}