#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

struct item {
  int x, y;
};

item mat[102][102];

int ans[102][102];

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      mat[i][j] = {i, j};
    }
  }
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int r;
      scanf("%d", &r); --r;
      item tmp = mat[r][0];
      for (int i = 0; i + 1 < m; ++i) {
        mat[r][i] = mat[r][i + 1];
      }
      mat[r][m - 1] = tmp;
    }
    if (t == 2) {
      int c;
      scanf("%d", &c); --c;
      item tmp = mat[0][c];
      for (int i = 0; i + 1 < n; ++i) {
        mat[i][c] = mat[i + 1][c];
      }
      mat[n - 1][c] = tmp;
    }
    if (t == 3) {
      int x, y, v;
      scanf("%d%d%d", &x, &y, &v); --x; --y;
      ans[mat[x][y].x][mat[x][y].y] = v;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}