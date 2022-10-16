#include <bits/stdc++.h>

int main() {
  std::vector<std::size_t> cnt(2);
  std::size_t n;
  std::cin >> n;
  while (n--) {
    std::uint32_t x;
    std::cin >> x;
    ++cnt[x % 2];
  }
  std::cout << std::min(cnt[0], cnt[1]) << '\n';
  return 0;
}