#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n, m;
char f[1001][1001];

int d1[1001][1001], d2[1001][1001], d3[1001][1001];

int dx[] = {-1, 0, 0, 1},
    dy[] = {0, -1, 1, 0};

void go(char c, int d[1001][1001]) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      d[i][j] = -1;

  vector<pair<int, int>> q;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (f[i][j] == c) {
        d[i][j] = 0;
        q.push_back({i, j});
      }

  for (int i = 0; i < q.size(); ++i) {
    auto p = q[i];
    for (int t = 0; t < 4; ++t) {
      int nx = p.first + dx[t], ny = p.second + dy[t];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && d[nx][ny] == -1 && f[nx][ny] != '#') {
        d[nx][ny] = d[p.first][p.second] + 1;
        q.push_back({nx, ny});
      }
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < m; ++j) {
  //     cout << d[i][j] << "  ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
}

void upd(int &r, int a) {
  if (r == -1 || r > a) r = a;
}

int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 0; i < n; ++i)
    gets(f[i]);

  go('1', d1);
  go('2', d2);
  go('3', d3);

  int d12 = -1, d13 = -1, d23 = -1, d123 = -1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (d1[i][j] != -1 && d2[i][j] != -1) upd(d12, d1[i][j] + d2[i][j] - 1);
      if (d1[i][j] != -1 && d3[i][j] != -1) upd(d13, d1[i][j] + d3[i][j] - 1);
      if (d3[i][j] != -1 && d2[i][j] != -1) upd(d23, d3[i][j] + d2[i][j] - 1);
      if (d1[i][j] != -1 && d2[i][j] != -1 && d3[i][j] != -1) upd(d123, d1[i][j] + d2[i][j] + d3[i][j] - 2);
    }
  }

  if (d12 == -1 || d13 == -1 || d23 == -1) {
    puts("-1");
    return 0;
  }

  // cout << d12 << " " << d13 << "  " << d23 << " " << d123 << endl;

  int ans = min(d12 + d13, d12 + d23);
  ans = min(ans, d13 + d23);
  ans = min(ans, d123);

  cout << ans << endl;

  return 0;
}