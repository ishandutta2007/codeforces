#include <bits/stdc++.h>
using namespace std;

int n, iter, flag[100100], dist[100100], degDist[100100];
vector<int> a[100100], path;

void findFurthest(int x, int par)
{
  for (int y : a[x])
    if (y != par)
    {
      dist[y] = dist[x] + 1;
      findFurthest(y, x);
    }
}

int findPath(int u, int v, int par)
{
  path.push_back(u);
  if (u == v)
    return 1;

  for (int x : a[u])
    if (x != par)
      if (findPath(x, v, u))
        return 1;

  path.pop_back();
  return 0;
}

int dfsCheck(int x, int par)
{
  for (int y : a[x])
    if (y != par)
    {
      dist[y] = dist[x] + 1;
      if (!dfsCheck(y, x))
        return 0;
    }

  if (flag[dist[x]] != iter)
  {
    degDist[dist[x]] = a[x].size();
    flag[dist[x]] = iter;
  }
  else if (a[x].size() != degDist[dist[x]])
    return 0;

  return 1;
}

void dfsLine(int x, int par)
{
  for (int y : a[x])
    if (y != par && a[y].size() <= 2)
    {
      dist[y] = dist[x] + 1;
      dfsLine(y, x);
    }
}

void verify(int x)
{
  dist[x] = 0;
  iter++;
  if (dfsCheck(x, 0))
  {
    cout << x << endl;
    exit(0);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x, y;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  dist[1] = 0;
  findFurthest(1, 0);
  int u = 1;
  for (int i = 2; i <= n; i++)
    if (dist[i] > dist[u])
      u = i;

  dist[u] = 0;
  findFurthest(u, 0);
  int v = 1;
  for (int i = 2; i <= n; i++)
    if (dist[i] > dist[v])
      v = i;

  verify(u);
  verify(v);

  findPath(u, v, 0);
  int center = path[path.size() / 2];
  verify(center);

  memset(dist, -1, sizeof dist);
  dist[center] = 0;
  dfsLine(center, 0);
  int closestLeaf = 0;
  for (int i = 1; i <= n; i++)
    if (dist[i] > 0 && a[i].size() == 1 && (!closestLeaf || dist[closestLeaf] > dist[i]))
      closestLeaf = i;
  if (closestLeaf)
    verify(closestLeaf);

  cout << -1 << endl;
}