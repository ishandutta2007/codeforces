#include <bits/stdc++.h>
using namespace std;

int n, k, dist[100100];
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

void dfs(int x, int par, int depth)
{
  int childCnt = a[x].size() - (par > 0);
  if (!childCnt)
  {
    if (depth != k)
    {
      cout << "No" << endl;
      exit(0);
    }
    return;
  }

  if (childCnt < 3)
  {
    cout << "No" << endl;
    exit(0);
  }

  for (int y : a[x])
    if (y != par)
      dfs(y, x, depth + 1);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i < n; i++)
  {
    int x, y;
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

  findPath(u, v, 0);
  if (dist[v] != k * 2)
  {
    cout << "No" << endl;
    return 0;
  }

  dfs(path[dist[v] / 2], 0, 0);
  cout << "Yes" << endl;
}