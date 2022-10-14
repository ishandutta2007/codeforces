#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, x;
    scanf("%d%d", &n, &x);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    std::sort(a.begin(), a.end());
    std::vector<int> dp(n + 1);
    for (int i = n; i--;) {
      dp[i] = dp[i + 1];
      int len = (x + a[i] - 1) / a[i];
      if (i + len <= n) {
        dp[i] = std::max(dp[i], dp[i + len] + 1);
      }
    }
    printf("%d\n", dp[0]);
  }
}