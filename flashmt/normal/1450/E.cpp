#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, color[333], dist[333][333];
vector<int> a[333];

void visit(int x)
{
  for (int y : a[x])
    if (color[y] < 0)
    {
      color[y] = color[x] ^ 1;
      visit(y);
    }
    else if (color[y] == color[x])
    {
      cout << "NO" << endl;
      exit(0);
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dist[i][j] = i == j ? 0 : oo;

  while (m--)
  {
    int x, y, v;
    cin >> x >> y >> v;
    a[x].push_back(y);
    a[y].push_back(x);
    dist[x][y] = 1;
    dist[y][x] = !v ? 1 : -1;
  }

  memset(color, -1, sizeof color);
  color[1] = 0;
  visit(1);

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  for (int i = 1; i <= n; i++)
    if (dist[i][i] < 0)
    {
      cout << "NO" << endl;
      return 0;
    }

  int maxDist = -1, u;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (dist[i][j] > maxDist)
      {
        maxDist = dist[i][j];
        u = i;
      }

  cout << "YES" << endl << maxDist << endl;
  for (int i = 1; i <= n; i++)
    cout << dist[u][i] << ' ';
}