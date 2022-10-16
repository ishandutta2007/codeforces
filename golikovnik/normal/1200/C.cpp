#include <bits/stdc++.h>

int main() {
  uint64_t n, m;
  unsigned q;
  std::cin >> n >> m >> q;
  auto g = std::gcd(n, m);
  auto get_component = [n, m, g](uint64_t inner, uint64_t pos) {
    return (pos - 1) / (inner == 1 ? (n / g) : (m / g));
  };
  while (q--) {
    uint64_t sx, sy, ex, ey;
    std::cin >> sx >> sy >> ex >> ey;
    std::cout << (get_component(sx, sy) == get_component(ex, ey)
                  ? "YES" : "NO") << '\n';
  }
  return 0;
}