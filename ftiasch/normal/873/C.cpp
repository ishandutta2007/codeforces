#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int m, n, k;
  scanf("%d%d%d", &m, &n, &k);
  // n - column
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[j][i]);
    }
  }
  int r0 = 0, r1 = 0;
  for (int i = 0; i < n; ++i) {
    std::pair<int, int> best{0, 0};
    int skips = 0, ones = 0;
    for (int j = 0; j < m; ++j) {
      ones += a[i][j];
      if (j >= k) {
        ones -= a[i][j - k];
        skips += a[i][j - k];
      }
      best = std::max(best, {ones, -skips});
    }
    r0 += best.first;
    r1 -= best.second;
  }
  printf("%d %d\n", r0, r1);
}