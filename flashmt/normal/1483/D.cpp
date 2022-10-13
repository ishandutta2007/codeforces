#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111000;

int n, m, Q, d[666][666], f[666], ans[666][666];
vector<pair<int, int>> a[666];
vector<pair<int, int>> q[666];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i == j) d[i][j] = 0;
      else d[i][j] = oo;

  for (int i = 0; i < m; i++)
  {
    int x, y, v;
    cin >> x >> y >> v;
    a[x].push_back({y, v});
    a[y].push_back({x, v});
    d[x][y] = d[y][x] = v;
  }

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);


  cin >> Q;
  for (int i = 0; i < Q; i++)
  {
    int u, v, len;
    cin >> u >> v >> len;
    q[u].push_back({v, len});
    q[v].push_back({u, len});
  }

  for (int u = 1; u <= n; u++)
  {
    for (int i = 1; i <= n; i++)
      f[i] = -1;
    for (auto [v, len] : q[u])
      for (int y = 1; y <= n; y++)
        if (d[v][y] < oo)
          f[y] = max(f[y], len - d[v][y]);

    for (int x = 1; x <= n; x++)
      if (d[u][x] < oo)
        for (auto [y, v] : a[x])
          if (d[u][x] + v <= f[y])
            ans[x][y] = ans[y][x] = 1;
  }

  int cnt = 0;
  for (int x = 1; x <= n; x++)
    for (auto [y, _] : a[x])
      cnt += ans[x][y];
  cout << cnt / 2 << endl;
}