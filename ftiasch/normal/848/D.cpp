#include <bits/stdc++.h>

static const int MOD = 1e9 + 7;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

const int N = 52;

int dp[N][N], dp1[N][N], inverse[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  inverse[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inverse[i] = 1LL * (MOD - MOD / i) * inverse[MOD % i] % MOD;
  }
  dp[0][1] = 1;
  for (int i = 1; i <= n; ++i) {
    // compute dp1[i][*]
    for (int x = 0; x < i; ++x) {
      int y = i - 1 - x;
      for (int xj = 1; xj <= x + 1; ++xj) {
        for (int yj = 1; yj <= y + 1; ++yj) {
          add(dp1[i][std::min(xj, yj)], 1LL * dp[x][xj] * dp[y][yj] % MOD);
        }
      }
    }
    for (int j = 1; j <= i + 1; ++j) {
      // uses dp1[i][j]
      //   printf("\tdp1[%d][%d]=%d\n", i, j, dp1[i][j]);
      for (int x = n; x >= i; --x) {
        for (int y = n + 1; y >= j; --y) {
          int ways = 1;
          for (int count = 1; i * count <= x && 1 + j * count <= y;
               ++count) {
            ways = 1LL * ways * (dp1[i][j] + count - 1) % MOD * inverse[count] %
                   MOD;
            add(dp[x][y], 1LL * ways * dp[x - i * count][y - j * count] % MOD);
          }
        }
      }
    }
    // for (int j = 1; j <= i + 1; ++j) {
    //   printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
    // }
  }
  printf("%d\n", dp[n][m]);
}