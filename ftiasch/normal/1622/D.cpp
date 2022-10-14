// #include "debug.h"

#include <bits/stdc++.h>

const int N = 5'000;
const int MOD = 998'244'353;

// int inv(int a) {
//   return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inv(MOD % a) % MOD;
// }

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int n, k, indices[N], binom[N + 1][N + 1];
char s[N + 1];

int main() {
  scanf("%d%d%s", &n, &k, s);
  for (int i = 0; i <= n; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      binom[i][j] = binom[i - 1][j - 1];
      add(binom[i][j], binom[i - 1][j]);
    }
  }
  int m = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      indices[m++] = i;
    }
  }
  if (m < k || k == 0) {
    puts("1");
  } else {
    int result = 0;
    for (int i = 0; i + k <= m; ++i) {
      int pre = i ? indices[i - 1] : -1;
      int nxt = i + k < m ? indices[i + k] : n;
      int len = nxt - pre - 1;
      add(result, binom[len][k]);
      if (i + k < m) {
        add(result, MOD - binom[nxt - indices[i] - 1][k - 1]);
      }
    }
    printf("%d\n", result);
  }
}