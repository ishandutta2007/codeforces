#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vvi mat(n, vi(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == '#')
        mat[i][j] = 1;
    }
  vector <set <int>> ver(m), hor(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (mat[i][j])
        continue;
      ver[j].insert(i);
      hor[i].insert(j);
    }
  vvi down(n, vi(m));
  vvi up = down, left = down, right = down;
  for (int i = n - 1; i >= 0; i--)
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 1) {
        down[i][j] = i - 1;
        continue;
      }
      if (i == n - 1)
        down[i][j] = n - 1;
      else
        down[i][j] = min(down[i + 1][j], i + k);
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 1) {
        up[i][j] = i + 1;
        continue;
      }
      if (!i)
        up[i][j] = 0;
      else
        up[i][j] = max(up[i - 1][j], i - k);
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 1) {
        left[i][j] = j + 1;
        continue;
      }
      if (!j)
        left[i][j] = 0;
      else
        left[i][j] = max(left[i][j - 1], j - k);
    }
  for (int i = 0; i < n; i++)
    for (int j = m - 1; j >= 0; j--) {
      if (mat[i][j] == 1) {
        right[i][j] = j - 1;
        continue;
      }
      if (j == m - 1)
        right[i][j] = m - 1;
      else
        right[i][j] = min(right[i][j + 1], j + k);
    }
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x1--, y1--, x2--, y2--;
  queue <int> q;
  q.push(x1 * m + y1);
  hor[x1].erase(y1);
  ver[y1].erase(x1);
  vi d(n * m, -1);
  d[x1 * m + y1] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    int x = v / m, y = v % m;
    vector <pair <int, int>> todel;
    auto itl = hor[x].lower_bound(left[x][y]);
    auto itr = hor[x].upper_bound(right[x][y]);
    while (itl != itr) {
      int u = *itl;
      todel.push_back({x, u});
      itl++;
    }
    itl = ver[y].lower_bound(up[x][y]);
    itr = ver[y].upper_bound(down[x][y]);
    while (itl != itr) {
      int u = *itl;
      todel.push_back({u, y});
      itl++;
    }
    for (auto &now : todel) {
      int xn = now.first, yn = now.second;
      d[xn * m + yn] = d[v] + 1;
      ver[yn].erase(xn);
      hor[xn].erase(yn);
      q.push(xn * m + yn);
    }
  }
  cout << d[x2 * m + y2];
  return 0;
}