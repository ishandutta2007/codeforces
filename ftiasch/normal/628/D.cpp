#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 2'000;
const int MOD = 1e9 + 7;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int m, magic, n, dp[2][2][2][N];
char a[N + 1], b[N + 1];

int main() {
  scanf("%d%d%s%s", &m, &magic, a, b);
  n = strlen(a);
  dp[0][0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    memset(dp[(i + 1) & 1], 0, sizeof(dp[(i + 1) & 1]));
    int ai = a[i] - '0';
    int bi = b[i] - '0';
    for (int greater = 0; greater < 2; ++greater) {
      for (int less = 0; less < 2; ++less) {
        for (int rem = 0; rem < m; ++rem) {
          for (int d = 0; d < 10; ++d) {
            if ((!greater && d < ai) || (!less && d > bi) ||
                ((i & 1) ^ (d == magic))) {
              continue;
            }
            add(dp[(i + 1) & 1][greater || (d > ai)][less || (d < bi)]
                  [(rem * 10 + d) % m],
                dp[i & 1][greater][less][rem]);
          }
        }
      }
    }
  }
  int result = 0;
  for (int greater = 0; greater < 2; ++greater) {
    for (int less = 0; less < 2; ++less) {
      add(result, dp[n & 1][greater][less][0]);
    }
  }
  printf("%d\n", result);
}