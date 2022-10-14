#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> two(n), five(n);
  for (int i = 0; i < n; ++i) {
    long long a;
    scanf("%lld", &a);
    while (a % 2 == 0) {
      a /= 2;
      two[i]++;
    }
    while (a % 5 == 0) {
      a /= 5;
      five[i]++;
    }
  }
  int sum_of_five = std::accumulate(five.begin(), five.end(), 0);
  std::vector<std::vector<int>> dp(m + 1,
                                   std::vector<int>(sum_of_five + 1, -1));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = m; j >= 1; --j) {
      for (int k = sum_of_five; k >= five[i]; --k) {
        int new_dp = dp[j][k];
        if (~dp[j - 1][k - five[i]]) {
          new_dp = std::max(new_dp, dp[j - 1][k - five[i]] + two[i]);
        }
        dp[j][k] = new_dp;
      }
    }
  }
  int result = 0;
  for (int k = 0; k <= sum_of_five; ++k) {
    if (~dp[m][k]) {
      result = std::max(result, std::min(dp[m][k], k));
    }
  }
  printf("%d\n", result);
}