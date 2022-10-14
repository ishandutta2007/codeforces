#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, limit;
  scanf("%d%d", &n, &limit);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::pair<int, std::pair<int, int>> best{0, {0, 0}};
  for (int j = 0, i = 0, zeros = 0; j < n; ++j) {
    zeros += !a[j];
    while (zeros > limit) {
      zeros -= !a[i++];
    }
    best = std::max(best, {j - i + 1, {i, j + 1}});
  }
  printf("%d\n", best.first);
  auto [l, r] = best.second;
  for (int i = 0; i < n; ++i) {
    printf("%d%c", l <= i && i < r ? 1 : a[i], " \n"[i + 1 == n]);
  }
}