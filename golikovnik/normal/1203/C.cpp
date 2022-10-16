#include <bits/stdc++.h>

int main() {
  unsigned n;
  std::cin >> n;
  std::vector<std::uint64_t> a(n);
  for (auto& x : a) {
    std::cin >> x;
  }
  auto my_gcd = [](auto x, auto y) {
    return std::gcd(x, y);
  };
  std::uint64_t g = 0;
  for (auto x : a) {
    g = std::gcd(g, x);
  }
  uint32_t result = 0;
  for (uint32_t p = 1; static_cast<uint64_t>(p) * p <= g; ++p) {
    if (g % p != 0) {
      continue;
    }
    ++result;
    if (static_cast<uint64_t>(p) * p != g) {
      ++result;
    }
  }
  std::cout << result << '\n';
  return 0;
}