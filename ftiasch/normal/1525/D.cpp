#include <bits/stdc++.h>

const int N = 5000;

int n, a[N], dp[2][N + 1];

void update(int &x, int a) { x = std::min(x, a); }

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  int half = n / 2;
  std::fill(dp[0], dp[0] + (n + 1), INT_MAX);
  dp[0][half] = 0;
  for (int i = 0; i < n; ++i) {
    std::fill(dp[(i + 1) & 1], dp[(i + 1) & 1] + (n + 1), INT_MAX);
    int *new_dp = dp[(i + 1) & 1] + half;
    for (int j = -half; j <= half; ++j) {
      int old = dp[i & 1][half + j];
      // 0+
      // 1-
      if (old < INT_MAX) {
        if (a[i]) {
          if (j > 0) {
            update(new_dp[j - 1], old + i);
          } else if (j - 1 >= -half) {
            update(new_dp[j - 1], old - i);
          }
        } else {
          update(new_dp[j], old);
          if (j < 0) {
            update(new_dp[j + 1], old + i);
          } else if (j + 1 <= half) {
            update(new_dp[j + 1], old - i);
          }
        }
      }
    }
  }
  printf("%d\n", dp[n & 1][half]);
}