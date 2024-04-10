#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;
const int BASE = 998244353;

int n, m, d[400][400];
long long ans[400][400];
vector<int> a[400];

int calc(int u, int v)
{
  vector<int> ways(n, 0);
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (d[u][i] + d[i][v] == d[u][v])
    {
      cnt++;
      ways[i] = 1;
    }
    else
    {
      for (int j : a[i])
        if (d[u][j] < d[u][i] && d[u][j] + 1 == d[u][i] && d[v][j] + 1 == d[v][i])
          ways[i]++;
    }

  if (cnt != d[u][v] + 1)
    return 0;

  long long res = 1;
  for (int i = 0; i < n; i++)
    res = res * ways[i] % BASE;
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      d[i][j] = d[j][i] = oo;

  while (m--)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
    d[x][y] = d[y][x] = 1;
  }

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  for (int u = 0; u < n; u++)
    for (int v = u; v < n; v++)
      ans[u][v] = ans[v][u] = calc(u, v);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cout << ans[i][j] << " \n"[j == n - 1];
}