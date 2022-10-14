#include <bits/stdc++.h>

#define DEBUG(...) fprintf(stderr, __VA_ARGS__)

const int N = 400;
const int C = 26;
const int MOD = 998244353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int n, count[C], dp[2][N + 1][N + 1][3], sum[N + 2][N + 2];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < C; ++i) {
    scanf("%d", count + i);
  }
  int gap = n >> 1;
  // n = 5 gap = 2
  // 01|234
  // n = 4 gap = 2
  // 01|23
  // (gap - 1) | gap
  dp[0][0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    memset(dp[i + 1 & 1], 0, sizeof(dp[i + 1 & 1]));
    for (int c0 = 0; c0 <= i; ++c0) {
      for (int c1 = 0; c0 + c1 <= i; ++c1) {
        for (int last = 0; last < 3; ++last) {
          int value = dp[i & 1][c0][c1][last];
          if (value) {
            if (i == 0 || i == gap || last != 0) {
              add(dp[i + 1 & 1][c0 + 1][c1][0], value);
            }
            if (i == 0 || i == gap || last != 1) {
              add(dp[i + 1 & 1][c0][c1 + 1][1], value);
            }
            if (i == 0 || i == gap || last != 2) {
              add(dp[i + 1 & 1][c0][c1][2], (C - 2LL) * value % MOD);
            } else {
              add(dp[i + 1 & 1][c0][c1][2], (C - 3LL) * value % MOD);
            }
          }
        }
      }
    }
  }
  for (int c0 = 0; c0 <= n; ++c0) {
    for (int c1 = 0; c0 + c1 <= n; ++c1) {
      for (int last = 0; last < 3; ++last) {
        int value = dp[n & 1][c0][c1][last];
        if (value) {
          add(sum[c0][c1], value);
        }
      }
    }
  }
  for (int x = n; x >= 0; --x) {
    for (int y = n; y >= 0; --y) {
      sum[x][y] = (static_cast<long long>(sum[x][y]) + sum[x + 1][y] +
                   sum[x][y + 1] + MOD - sum[x + 1][y + 1]) %
                  MOD;
    }
  }
  int result = sum[0][0];
  for (int i = 0; i < C; ++i) {
    add(result, MOD - sum[count[i] + 1][0]);
  }
  for (int i = 0; i < C; ++i) {
    for (int j = i + 1; j < C; ++j) {
      add(result, sum[count[i] + 1][count[j] + 1]);
    }
  }
  printf("%d\n", result);
}