#include <bits/stdc++.h>

const int N = 501;

int n, m, sqr[N][N], ver[N], dp[4][N][N], sum[N + 1 >> 1][N][N];
char grid[N][N + 1];

template <int rev> struct OrderT {
  OrderT(int n) : n(n) {}

  int operator[](int i) const { return rev ? n - 1 - i : i; }

  int n;
};

template <char symbol, int xrev, int yrev> void prepare(int dp[N][N]) {
  OrderT<xrev> x(n);
  OrderT<yrev> y(m);
  memset(ver, 0, sizeof(ver));
  for (int i = 0; i < n; ++i) {
    int hor = 0;
    for (int j = 0; j < m; ++j) {
      int &ref = dp[x[i]][y[j]];
      if (grid[x[i]][y[j]] == symbol) {
        hor++, ver[j]++;
        ref = std::min(hor, ver[j]);
        if (i && j) {
          ref = std::min(ref, dp[x[i - 1]][y[j - 1]] + 1);
        }
      } else {
        hor = ver[j] = ref = 0;
      }
    }
  }
}

int main() {
  int q;
  while (scanf("%d%d%d", &n, &m, &q) == 3) {
    for (int i = 0; i < n; ++i) {
      scanf("%s", grid[i]);
    }
    prepare<'R', 0, 0>(dp[0]);
    prepare<'G', 0, 1>(dp[1]);
    prepare<'B', 1, 1>(dp[2]);
    prepare<'Y', 1, 0>(dp[3]);
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        int length = std::min(std::min(dp[0][i - 1][j - 1], dp[1][i - 1][j]),
                              std::min(dp[2][i][j], dp[3][i][j - 1]));
        for (int k = 1; k <= length; ++k) {
          sum[k][i - k][j - k]++;
        }
      }
    }
    for (int k = 1; k + k <= n; ++k) {
      for (int i = n; i--;) {
        for (int j = m; j--;) {
          sum[k][i][j] +=
              sum[k][i + 1][j] + sum[k][i][j + 1] - sum[k][i + 1][j + 1];
        }
      }
    }
    while (q--) {
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      x1--, y1--;
      int low = 0;
      int high = std::min(x2 - x1, y2 - y1) >> 1;
      while (low < high) {
        int middle = low + high + 1 >> 1;
        int x0 = x2 + 1 - middle * 2;
        int y0 = y2 + 1 - middle * 2;
        if (sum[middle][x1][y1] - sum[middle][x0][y1] - sum[middle][x1][y0] +
            sum[middle][x0][y0]) {
          low = middle;
        } else {
          high = middle - 1;
        }
      }
      printf("%d\n", 4 * low * low);
    }
  }
}