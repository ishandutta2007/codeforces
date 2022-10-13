#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n, q;
  cin >> m >> n >> q;

  auto getLastRow = [&](int i, int j)
  {
    int d = i - j, ii = n - 1 + d;
    return ii >= 0 && ii < m ? ii : m - 1;
  };

  long long ans = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      ans += (getLastRow(i, j) - i) * 2 + 1;
      if (j + 1 < n)
        ans += getLastRow(i, j + 1) - i + 1;
      if (i + 1 < m)
        ans += getLastRow(i + 1, j) - i;
    }

  vector<vector<int>> blocked(m, vector<int>(n));
  while (q--)
  {
    int x, y;
    cin >> x >> y;
    x--; y--;
    for (int turn : {0, 1})
    {
      int dx = turn, dy = 1 - turn;
      int xx = x, yy = y, r = 1;
      while (1)
      {
        xx += dx;
        yy += dy;
        if (xx >= m || yy >= n || blocked[xx][yy])
          break;
        swap(dx, dy);
        r++;
      }

      dx = 1 - turn;
      dy = turn;
      xx = x;
      yy = y;
      int l = 1;
      while (1)
      {
        xx -= dx;
        yy -= dy;
        if (xx < 0 || yy < 0 || blocked[xx][yy])
          break;
        swap(dx, dy);
        l++;
      }

      if (blocked[x][y]) ans += l * r;
      else ans -= l * r;
    }

    if (!blocked[x][y]) ans++;
    else ans--;
    blocked[x][y] ^= 1;
    cout << ans << '\n';
  }
}