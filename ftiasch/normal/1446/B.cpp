#include <bits/stdc++.h>

const int N = 5000;

int n, m, dp[2][N + 1];
char a[N + 1], b[N + 1];

int main() {
  while (scanf("%d%d%s%s", &n, &m, a, b) == 4) {
    memset(dp, 0, sizeof(dp));
    int result = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int &ref = dp[i + 1 & 1][j + 1];
        ref = std::max(std::max(dp[i & 1][j + 1], dp[i + 1 & 1][j]) - 1, 0);
        if (a[i] == b[j]) {
          ref = std::max(ref, dp[i & 1][j] + 2);
        }
        result = std::max(result, ref);
      }
    }
    printf("%d\n", result);
  }
}