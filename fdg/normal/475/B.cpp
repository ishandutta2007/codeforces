#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int dx[] = {-1, 1, 0, 0},
    dy[] = {0, 0, -1, 1};

int row[22], col[22], n, m;

bool in(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

bool good(int sx, int sy) {
  bool used[22][22] = {0};
  used[sx][sy] = true;
  while (true) {
    bool was = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (used[i][j]) {
          int x = i + dx[row[i]], y = j + dy[row[i]];
          if (in(x, y)) {
            if (!used[x][y]) {
              used[x][y] = true;
              was = true;
            }
          }
          x = i + dx[col[j]], y = j + dy[col[j]];
          if (in(x, y)) {
            if (!used[x][y]) {
              used[x][y] = true;
              was = true;
            }
          }
        }
      }
    }
    if (!was) break;
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (!used[i][j]) return false;
  return true;
}

int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 0; i < n; ++i) {
    char c;
    scanf("%c", &c);
    if (c == '>') row[i] = 3;
    else row[i] = 2;
  }
  scanf("\n");
  for (int i = 0; i < m; ++i) {
    char c;
    scanf("%c", &c);
    if (c == '^') col[i] = 0;
    else col[i] = 1;
  }
  scanf("\n");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      if (!good(i, j)) {
        puts("NO");
        return 0;
      }
  }
  puts("YES");
  return 0;
}