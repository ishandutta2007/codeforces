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

int64_t gcd(int64_t x, int64_t y) {
  return y == 0 ? x : gcd(y, x % y);
}

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int> perm(n);
  for (int i = 0; i < n; i++) {
    in >> perm[i];
    perm[i]--;
  }
  int64_t period = 1;
  for (int i = 0; i < n; i++) {
    int cur = i;
    for (int j = 0; j < n; j++) {
      cur = perm[cur];
      if (cur == i) {
        period = period * (j + 1) / gcd(period, j + 1);
        cur = -1;
        break;
      }
    }
    if (cur >= 0) {
      out << -1 << std::endl;
      return;
    }
  }
  if (period % 2 == 0) {
    period /= 2;
  }
  out << period << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}