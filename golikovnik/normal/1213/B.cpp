#include <bits/stdc++.h>

std::size_t solve() {
  std::size_t n;
  std::cin >> n;
  std::vector<std::uint32_t> a(n);
  for (auto& x : a) {
    std::cin >> x;
  }
  std::vector<std::uint32_t> suff(n);
  suff[n - 1] = a[n - 1];
  for (std::size_t i = n - 1; i--; ) {
    suff[i] = std::min(a[i], suff[i + 1]);
  }
  std::size_t answer = 0;
  for (std::size_t i = 0; i != n - 1; ++i) {
    answer += suff[i + 1] < a[i];
  }
  return answer;
}

int main() {
  unsigned t;
  std::cin >> t;
  while (t--) {
    std::cout << solve() << '\n';
  }
  return 0;
}