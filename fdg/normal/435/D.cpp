#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char f[405][405];

int sum[4][405][405];
int dx[] = {-1, -1, -1, 0},
    dy[] = {1, -1, 0, -1};

int n, m;

bool in(int x, int y) {
  return 1 <= x && x <= n && 1 <= y && y <= m;
}

int get(int t, int x1, int y1, int x2, int y2) {
  if (!in(x1, y1) || !in(x2, y2)) return 1;
  if (t == 0 && x1 < x2 ||
      t == 1 && x1 < x2 ||
      t == 2 && x1 < x2 ||
      t == 3 && y1 < y2) {
    swap(x1, x2);
    swap(y1, y2);
  }
  return sum[t][x1][y1] - sum[t][x2 + dx[t]][y2 + dy[t]];
}

int main() {
  scanf("%d%d\n", &n, &m);
  // n = 400; m = 400;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%c", &f[i][j]);
      // f[i][j] = '0';
    }
    scanf("\n");
  }
  for (int t = 0; t < 4; ++t) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        sum[t][i][j] = (f[i][j] == '1') + sum[t][i + dx[t]][j + dy[t]];
      }
  }
  int ans = 0, up = max(n, m);
  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= m; ++y) {
      if (f[x][y] == '0') {
        for (int d = 1; d <= up; ++d) {
          int t1 = get(0, x - d, y, x, y - d) == 0 && get(2, x - d, y, x, y) == 0 && get(3, x, y - d, x, y) == 0;
          int t2 = get(1, x - d, y, x, y + d) == 0 && get(2, x - d, y, x, y) == 0 && get(3, x, y + d, x, y) == 0;
          int t3 = get(0, x + d, y, x, y + d) == 0 && get(2, x + d, y, x, y) == 0 && get(3, x, y + d, x, y) == 0;
          int t4 = get(1, x + d, y, x, y - d) == 0 && get(2, x + d, y, x, y) == 0 && get(3, x, y - d, x, y) == 0;
          int t5 = get(0, x - d, y, x, y - d) == 0 && get(1, x - d, y, x, y + d) == 0 && get(3, x, y - d, x, y + d) == 0;
          int t6 = get(0, x + d, y, x, y + d) == 0 && get(1, x - d, y, x, y + d) == 0 && get(2, x - d, y, x + d, y) == 0;
          int t7 = get(0, x + d, y, x, y + d) == 0 && get(1, x + d, y, x, y - d) == 0 && get(3, x, y - d, x, y + d) == 0;
          int t8 = get(0, x - d, y, x, y - d) == 0 && get(1, x + d, y, x, y - d) == 0 && get(2, x - d, y, x + d, y) == 0;
          ans += t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8; 
          // if (t1)
          //   cout << x << "  " << y << " " << d << endl;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}