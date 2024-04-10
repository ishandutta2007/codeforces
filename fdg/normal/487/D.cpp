#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n, m, q;
char mat[100002][15];

const int BS = 200;

pair<int, int> wh[100002][14];

void build(int row) {
  for (int i = row; i < n && i < row + BS; ++i) {
    for (int j = 0; j < m; ++j)
      wh[i][j] = make_pair(-2, -2);
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '<') {
        wh[i][j] = make_pair(i, -1);
      } else {
        break;
      }
    }
    for (int j = m - 1; j >= 0; --j) {
      if (mat[i][j] == '>') {
        wh[i][j] = make_pair(i, m);
      } else {
        break;
      }
    }
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '^') {
        if (i == row) wh[i][j] = make_pair(i - 1, j);
        else wh[i][j] = wh[i - 1][j];
        for (int jj = j - 1; jj >= 0; --jj) {
          if (mat[i][jj] == '>') wh[i][jj] = wh[i][j];
          else break;
        }
        for (int jj = j + 1; jj < m; ++jj) {
          if (mat[i][jj] == '<') wh[i][jj] = wh[i][j];
          else break;
        }
      }
    }
  }
}

pair<int, int> get(int r, int c) {
  pair<int, int> ret = wh[r][c];
  while (true) {
    if (ret.first < -1) break;
    if (ret.first < 0 || ret.second < 0 || ret.second == m) break;
    ret = wh[ret.first][ret.second];
  }
  return ret;
}

int main() {
  scanf("%d%d%d\n", &n, &m, &q);
  for (int i = 0; i < n; ++i)
    gets(mat[i]);
  for (int i = 0; i < n; i += BS)
    build(i);
  // auto par = wh[0][0];
  // printf("%d %d\n", par.first, par.second);
  // return 0;
  while (q--) {
    char t, c; int x, y;
    scanf("%c %d %d", &t, &x, &y);
    // cout << "T: " << t << endl;
    if (t == 'A') {
      auto p = get(x - 1, y - 1);
      printf("%d %d\n", p.first + 1, p.second + 1);
    } else {
      scanf(" %c", &c);
      mat[x - 1][y - 1] = c;
      build(((x - 1) / BS) * BS);
    }
    scanf("\n");
  }
  // cout << sizeof(wh) / 1024.0 / 1024 << endl;
  return 0;
}