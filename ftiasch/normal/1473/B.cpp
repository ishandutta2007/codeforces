#include <bits/stdc++.h>

std::pair<std::string, int> decompose(const std::string &s) {
  int n = s.size();
  for (int d = 1; d <= n; ++d) {
    if (n % d == 0 && s.substr(0, n - d) == s.substr(d, n - d)) {
      return {s.substr(0, d), n / d};
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    std::string a, b;
    std::cin >> a >> b;
    auto [p, n] = decompose(a);
    auto [q, m] = decompose(b);
    if (p == q) {
      int k = n / std::__gcd(n, m) * m;
      for (int i = 0; i < k; ++i) {
        std::cout << p;
      }
      std::cout << "\n";
    } else {
      std::cout << -1 << "\n";
    }
  }
}