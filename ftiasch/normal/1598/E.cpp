#include <bits/stdc++.h>

const int N = 1'001;

int n, m, q, a[N][N], dp[N][N][2], result;

int get(int i, int j) { return std::max(dp[i][j][0] + dp[i][j][1] - 1, 0); }

void update(int i, int j) {
  if (1 <= i && i <= n && 1 <= j && j <= m) {
    result -= get(i, j);
    if (a[i][j]) {
      dp[i][j][0] = dp[i][j - 1][1] + 1;
      dp[i][j][1] = dp[i - 1][j][0] + 1;
    } else {
      dp[i][j][0] = dp[i][j][1] = 0;
    }
    result += get(i, j);
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      a[i][j] = 1;
      dp[i][j][0] = dp[i][j - 1][1] + 1;
      dp[i][j][1] = dp[i - 1][j][0] + 1;
      result += get(i, j);
    }
  }
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x][y] ^= 1;
    int parity = 0;
    while (x <= n || y <= m) {
      if (parity) {
        update(x, y);
        update(x + 1, y - 1);
        x++;
      } else {
        update(x, y);
        y++;
      }
      parity ^= 1;
    }
    printf("%d\n", result);
  }
}