#include <bits/stdc++.h>

bool solve() {
  unsigned n;
  std::cin >> n;
  std::vector<unsigned> p(n);
  for (auto& x : p) {
    std::cin >> x;
    --x;
  }
  if (n < 3) {
    return true;
  }
  bool clockwise = (p[0] + 1) % n == p[1];
  for (std::size_t i = 1; i != n; ++i) {
    auto expect = clockwise ? (p[i] + 1) % n : (p[i] - 1 + n) % n;
    if (p[(i + 1) % n] != expect) {
      return false;
    }
  }
  return true;
}

int main() {
  unsigned q;
  std::cin >> q;
  while (q--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}