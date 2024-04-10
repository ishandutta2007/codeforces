#include <bits/stdc++.h>

bool solve() {
  unsigned n;
  std::cin >> n;
  int32_t m, k;
  std::cin >> m >> k;
  std::vector<int32_t> heights(n);
  for (auto& h : heights) {
    std::cin >> h;
  }
  for (unsigned i = 0; i + 1 < n; ++i) {
    auto need_height = std::max(0, heights[i + 1] - k);
    auto delta = heights[i] - need_height;
    m += delta;
    if (m < 0) {
      return false;
    }
  }
  return true;
}

int main() {
  unsigned tests;
  std::cin >> tests;
  while (tests--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}