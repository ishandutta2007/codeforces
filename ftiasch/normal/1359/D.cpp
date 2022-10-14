#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::vector<int> values(a);
  std::sort(values.begin(), values.end());
  values.erase(std::unique(values.begin(), values.end()), values.end());
  int result = 0;
  int inf = 30 * n + 1;
  for (int m : values) {
    std::array<int, 2> dp{0, -inf};
    for (int x : a) {
      if (x > m) {
        dp = {0, -inf};
      } else if (x < m) {
        dp = {std::max(dp[0] + x, 0), dp[1] + x};
      } else {
        dp = {std::max(dp[0] + x, 0), std::max(dp[0] + x, dp[1] + x)};
      }
      result = std::max(result, dp[1] - m);
    }
  }
  printf("%d\n", result);
}