#include <bits/stdc++.h>

int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  std::vector<std::tuple<int, int, int, int>> e(n);
  for (int i = 0, s, a; i < n; ++i) {
    scanf("%d%d", &s, &a);
    e[i] = {std::max(s, a), s, s, a};
  }
  std::ranges::sort(e);
  int result = 0;
  for (auto [_, __, s, a] : e) {
    if (d <= s) {
      result++;
      d = std::max(d, a);
    }
  }
  printf("%d\n", result);
}