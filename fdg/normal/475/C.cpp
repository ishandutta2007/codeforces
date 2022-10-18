#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char f[1002][1002], tmp[1002][1002];

int solve(int n, int m) {
  int sx = -1, sy = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (f[i][j] == 'X') {
        if (sx == -1 || sx > i || sx == i && sy > j) {
          sx = i; sy = j;
        }
      }
    }
  }
  int h = 0, w = 1;
  while (sx + h < n && f[sx + h][sy] == 'X') ++h;
  if (sx + h < n) {
    for (int j = 0; j < m; ++j) {
      if (f[sx + h][j] == 'X') {
        for (int jj = m - 1; jj >= 0; --jj) {
          if (f[sx][jj] == 'X') {
            w = jj - j + 1;
            break;
          }
        }
        break;
      }
    }
  }
  // cout << h << "  " << w << endl;
  bool ok = true;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      tmp[i][j] = '.';

  int row[1002] = {0}, column[1002] = {0};
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (f[i][j] == 'X') {
        row[i] = max(row[i], j);
        column[j] = max(column[j], i);
      }
    }

  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      tmp[sx + i][sy + j] = 'X';

  while (true) {
    if (row[sx] >= sy + w) {
      for (int i = 0; i < h; ++i)
        tmp[sx + i][sy + w] = 'X';
      ++sy;
    } else if (column[sy] >= sx + h) {
      for (int j = 0; j < w; ++j)
        tmp[sx + h][sy + j] = 'X';
      ++sx;
    } else {
      break;
    }
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (tmp[i][j] != f[i][j]) ok = false;
  if (w <= 0 || !ok)
    return 1000000000;
  return h * w;
}

int main() {
  int n, m;
  scanf("%d%d\n", &n, &m);
  for (int i = 0; i < n; ++i)
    gets(f[i]);
  int ans = 1000000000;
  ans = solve(n, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      tmp[j][i] = f[i][j];
  }
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      f[i][j] = tmp[i][j];
  ans = min(ans, solve(m, n));
  if (ans == 1000000000) ans = -1;
  printf("%d\n", ans);
  return 0;
}