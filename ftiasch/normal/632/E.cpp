#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, limit;
  scanf("%d%d", &n, &limit);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a.begin(), a.end());
  for (int i = 1; i < n; ++i) {
    a[i] -= a[0];
  }
  int m = limit * a[n - 1];
  std::vector<int> dp(m + 1, limit + 1);
  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = a[i]; j <= m; ++j) {
      dp[j] = std::min(dp[j], dp[j - a[i]] + 1);
    }
  }
  for (int j = 0; j <= m; ++ j) {
    if (dp[j] <= limit) {
      printf("%d ", a[0] * limit + j);
    }
  }
}