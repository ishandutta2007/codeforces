#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a[555];
  int m, n, h[555][555] = {0}, v[555][555] = {0}, Q, x, y, xx, yy;

  cin >> m >> n;
  for (int i = 1; i <= m; i++)
  {
    cin >> a[i];
    a[i] = "#" + a[i];
    for (int j = 1; j <= n; j++)
    {
      h[i][j] = h[i - 1][j] + h[i][j - 1] - h[i - 1][j - 1];
      v[i][j] = v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
      if (a[i][j] == '#') continue;
      if (i && a[i - 1][j] == '.') v[i][j]++;
      if (j && a[i][j - 1] == '.') h[i][j]++;
    }
  }

  cin >> Q;
  while (Q--)
  {
    cin >> x >> y >> xx >> yy;
    int ans = v[xx][yy] + v[x][y - 1] - v[x][yy] - v[xx][y - 1];
    ans += h[xx][yy] + h[x - 1][y] - h[xx][y] - h[x - 1][yy];
    cout << ans << '\n';
  }
}