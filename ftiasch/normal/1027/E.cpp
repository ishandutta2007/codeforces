#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 500;
const int MOD = 998'244'353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int dp[N + 1][N + 1];

int main() {
  int n, limit;
  scanf("%d%d", &n, &limit);
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int max = 0; max <= i; ++max) {
      for (int j = 1; i + j <= n; ++j) {
        add(dp[i + j][std::max(max, j)], dp[i][max]);
      }
    }
  }
  int result = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n && i * j < limit; ++j) {
      add(result, 2LL * dp[n][i] * dp[n][j] % MOD);
    }
  }
  printf("%d\n", result);
}