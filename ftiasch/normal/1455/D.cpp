#include <bits/stdc++.h>

void update(int &x, int a) { x = ~x ? std::min(x, a) : a; }

const int N = 501;

int a[N], dp[2][2][N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    memset(dp, -1, sizeof(dp));
    // 0 - inplace x
    // 1 - swapped out a[i]
    dp[0][0][x] = 0;
    for (int i = 1; i <= n; ++i) {
      memset(dp[i & 1], -1, sizeof(dp[i & 1]));
      for (int t = 0; t < 2; ++t) {
        for (int j = 0; j < N; ++j) {
          int old_dp = dp[(i + 1) & 1][t][j];
          if (~old_dp) {
            int x = j;
            int pre = a[i - 1];
            if (t) {
              std::swap(x, pre);
            }
            if (pre <= a[i]) {
              update(dp[i & 1][0][x], old_dp);
            }
            if (x < a[i] && pre <= x) {
              update(dp[i & 1][1][x], old_dp + 1);
            }
          }
        }
      }
    }
    int result = -1;
    for (int t = 0; t < 2; ++t) {
      for (int j = 0; j < N; ++j) {
        int old_dp = dp[n & 1][t][j];
        if (~old_dp) {
          update(result, old_dp);
        }
      }
    }
    printf("%d\n", result);
  }
}