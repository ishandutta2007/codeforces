#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    std::sort(a.begin(), a.end());
    std::vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int t = 1; t <= 2 * n; ++t) {
      for (int i = n; i >= 1; --i) {
        dp[i] = std::min(dp[i], dp[i - 1] + std::abs(a[i - 1] - t));
      }
    }
    printf("%d\n", dp[n]);
  }
}