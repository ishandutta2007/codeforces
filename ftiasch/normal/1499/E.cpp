#include <bits/stdc++.h>

const int MOD = 998'244'353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

const int N = 1001;

int count_empty(int n, char *s) {
  int result = 0, len = 0;
  for (int i = n - 1; i >= 0; --i) {
    len = i + 1 < n && s[i] != s[i + 1] ? len + 1 : 1;
    add(result, len);
  }
  return result;
}

char x[N], y[N];
int dp[2][N][2];

int main() {
  scanf("%s%s", x, y);
  int n = strlen(x);
  int m = strlen(y);
  int result = 0;
  for (int i = n; i >= 0; --i) {
    memset(dp[i & 1], 0, sizeof(dp[i & 1]));
    char pre0 = i ? x[i - 1] : '\0';
    for (int j = m; j >= 0; --j) {
      char pre1 = j ? y[j - 1] : '\0';
      add(dp[i & 1][j][0], 1);
      add(dp[i & 1][j][1], 1);
      if (i < n) {
        if (x[i] != pre0) {
          add(dp[i & 1][j][0], dp[(i + 1) & 1][j][0]);
        }
        if (x[i] != pre1) {
          add(dp[i & 1][j][1], dp[(i + 1) & 1][j][0]);
        }
        add(result, dp[(i + 1) & 1][j][0]);
      }
      if (j < m) {
        if (y[j] != pre0) {
          add(dp[i & 1][j][0], dp[i & 1][j + 1][1]);
        }
        if (y[j] != pre1) {
          add(dp[i & 1][j][1], dp[i & 1][j + 1][1]);
        }
        add(result, dp[i & 1][j + 1][1]);
      }
    }
  }
  add(result, MOD - (n + 1LL) * count_empty(m, y) % MOD);
  add(result, MOD - (m + 1LL) * count_empty(n, x) % MOD);
  printf("%d\n", result);
}