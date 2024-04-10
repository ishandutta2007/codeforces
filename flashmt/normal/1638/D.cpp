#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vector<vector<int>> a(m, vector<int>(n));
  vector<vector<int>> flag(m, vector<int>(n));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  auto canPaint = [&](int x, int y)
  {
    int color = 0;
    for (int i : {x, x + 1})
      for (int j : {y, y + 1})
        if (i < 0 || i >= m || j < 0 || j >= n) return 0;
        else if (a[i][j])
        {
          if (!color) color = a[i][j];
          else if (color != a[i][j]) return 0;
        }

    return color;
  };

  vector<tuple<int, int, int>> q;
  for (int i = 0; i < m - 1; i++)
    for (int j = 0; j < n - 1; j++)
    {
      int color = canPaint(i, j);
      if (color)
      {
        q.push_back({i, j, color});
        flag[i][j] = 1;
      }
    }

  for (int i = 0; i < size(q); i++)
  {
    auto [x, y, c] = q[i];
    for (int xx : {x, x + 1})
      for (int yy : {y, y + 1})
        a[xx][yy] = 0;

    for (int xx = x - 1; xx <= x + 1; xx++)
      for (int yy = y - 1; yy <= y + 1; yy++)
      {
        int cc = canPaint(xx, yy);
        if (cc && !flag[xx][yy])
        {
          q.push_back({xx, yy, cc});
          flag[xx][yy] = 1;
        }
      }
  }

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j])
      {
        cout << -1 << endl;
        return 0;
      }

  cout << size(q) << '\n';
  reverse(begin(q), end(q));
  for (auto [x, y, c] : q)
    cout << x + 1 << ' ' << y + 1 << ' ' << c << '\n';
}