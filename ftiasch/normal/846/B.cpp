#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m, T;
  scanf("%d%d%d", &n, &m, &T);
  std::vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a.begin(), a.end());
  for (int i = 1; i < m; ++i) {
    a[i] += a[i - 1];
  }
  std::vector<long long> dp(n * (m + 1) + 1, T + 1);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = n * (m + 1); j >= 0; --j) {
      for (int k = 1; k <= m + 1 && k <= j; ++k) {
        dp[j] = std::min(dp[j], dp[j - k] + a[std::min(k, m) - 1]);
      }
    }
  }
  int result = n * (m + 1);
  while (dp[result] > T) {
    result--;
  }
  printf("%d\n", result);
}