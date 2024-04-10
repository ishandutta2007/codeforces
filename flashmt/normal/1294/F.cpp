#include <bits/stdc++.h>
using namespace std;

int n, flag[200200], depth[200200];
vector<int> a[200200];

void findFurthest(int x, int par, int dist[])
{
  for (int y : a[x])
    if (y != par)
    {
      dist[y] = dist[x] + 1;
      findFurthest(y, x, dist);
    }
}

pair<int, int> findDiameter()
{
  int dist[200200] = {0};
  findFurthest(1, 0, dist);
  int u = 1;
  for (int i = 2; i <= n; i++)
    if (dist[i] > dist[u])
      u = i;

  dist[u] = 0;
  findFurthest(u, 0, dist);
  int v = 1;
  for (int i = 2; i <= n; i++)
    if (dist[i] > dist[v])
      v = i;

  return {u, v};
}

int findPath(int u, int v, int par, vector<int> &path)
{
  path.push_back(u);
  if (u == v)
    return 1;

  for (int x : a[u])
    if (x != par)
      if (findPath(x, v, u, path))
        return 1;

  path.pop_back();
  return 0;
}

void dfs(int x)
{
  for (int y : a[x])
    if (!flag[y])
    {
      flag[y] = 1;
      depth[y] = depth[x] + 1;
      dfs(y);
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  auto [u, v] = findDiameter();
  vector<int> path;
  findPath(u, v, 0, path);
  int w = 0;
  for (int x : path)
  {
    flag[x] = 1;
    if (x != u && x != v)
      w = x;
  }

  for (int x : path)
    dfs(x);

  for (int i = 1; i <= n; i++)
    if (depth[i] > depth[w])
      w = i;

  cout << path.size() + depth[w] - 1 << endl << u << ' ' << v << ' ' << w << endl;
}