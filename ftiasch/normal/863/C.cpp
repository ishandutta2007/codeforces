#line 1 "sol.cpp"
#include <bits/stdc++.h>

using PLL = std::pair<long long, long long>;

int a[3][3], b[3][3];
std::pair<int, int> to[2][3][3];
PLL points[2][3][3];

PLL operator+(const PLL &a, const PLL &b) {
  return {a.first + b.first, a.second + b.second};
}

int main() {
  long long n;
  int x, y;
  scanf("%lld%d%d", &n, &x, &y);
  x--;
  y--;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      scanf("%d", a[i] + j);
      a[i][j]--;
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      scanf("%d", b[i] + j);
      b[i][j]--;
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      to[0][i][j] = {a[i][j], b[i][j]};
      points[0][i][j] = {(i + 3 - j) % 3 == 1, (j + 3 - i) % 3 == 1};
    }
  }
  PLL result{0, 0};
  for (int k = 0; n >> k; ++k) {
    if (n >> k & 1) {
      result = result + points[k & 1][x][y];
      std::tie(x, y) = to[k & 1][x][y];
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        auto [ii, jj] = to[k & 1][i][j];
        to[(k + 1) & 1][i][j] = to[k & 1][ii][jj];
        points[(k + 1) & 1][i][j] = points[k & 1][i][j] + points[k & 1][ii][jj];
      }
    }
  }
  printf("%lld %lld\n", result.first, result.second);
}