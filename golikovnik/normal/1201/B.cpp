#include <bits/stdc++.h>

int main() {
  unsigned n;
  std::cin >> n;
  std::vector<std::uint32_t> a(n);
  std::uint64_t sum = 0;
  for (auto& x : a) {
    std::cin >> x;
    sum += x;
  }
  auto max = *std::max_element(a.begin(), a.end());
  bool ok = (sum % 2 == 0) && (max <= (sum - max));
  std::cout << (ok ? "YES" : "NO") << '\n';
  return 0;
}