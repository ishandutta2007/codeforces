#include <bits/stdc++.h>

uint64_t gcd(uint64_t a, uint64_t b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  int T;
  std::cin >> T;
  uint64_t a, m;
  while (T--) {
    std::cin >> a >> m;
    m /= gcd(a, m);
    uint64_t phi = 1;
    for (uint64_t d = 2; d * d <= m; ++d) {
      if (m % d == 0) {
        while (m % d == 0) {
          m /= d;
          phi *= d;
        }
        phi = phi / d * (d - 1);
      }
    }
    if (m > 1) {
      phi *= m - 1;
    }
    std::cout << phi << std::endl;
  }
}