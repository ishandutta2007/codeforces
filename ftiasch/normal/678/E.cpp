#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 18;

int n;
double p[N][N], dp[1 << N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%lf", p[i] + j);
    }
  }
  dp[1] = 1.0;
  for (int mask = 2; mask < 1 << n; ++mask) {
    for (int i = 0; i < n; ++i) {
      if (mask >> i & 1) {
        for (int j = i + 1; j < n; ++j) {
          if (mask >> j & 1) {
            dp[mask] = std::max(dp[mask], dp[mask ^ (1 << i)] * p[j][i] +
                                          dp[mask ^ (1 << j)] * p[i][j]);
          }
        }
      }
    }
  }
  printf("%.9f\n", dp[(1 << n) - 1]);
}