#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    std::vector<int> dp(m + 1);
    dp[0] = 0;
    dp[1] = x;
    for (int i = 2; i <= m; ++i) {
      dp[i] = std::min(dp[i - 1] + x, dp[i - 2] + y);
    }
    int result = 0;
    std::vector<char> row(m + 1);
    for (int i = 0; i < n; ++i) {
      scanf("%s", row.data());
      for (int j = 0; j < m;) {
        if (row[j] == '*') {
          j++;
        } else {
          int k = j;
          while (row[k] == '.') {
            k++;
          }
          result += dp[k - j];
          j = k;
        }
      }
    }
    printf("%d\n", result);
  }
}