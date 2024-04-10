#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;

int ds[500500], par[500500], parEdge[500500], depth[500500], anc[500500], ans[500500];
vector<pair<int, int>> a[500500];

int get(int ds[], int x)
{
  return x == ds[x] ? x : ds[x] = get(ds, ds[x]);
}

void dfs(int x)
{
  for (auto [y, id] : a[x])
    if (y != par[x])
    {
      par[y] = x;
      parEdge[y] = id;
      depth[y] = depth[x] + 1;
      dfs(y);
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k, m;
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++)
    ds[i] = i;
  for (int i = 0; i < k; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back({y, i});
    a[y].push_back({x, i});
    ds[get(ds, x)] = get(ds, y);
    ans[i] = oo;
  }

  vector<tuple<int, int, int>> unusedEdges;
  for (int i = 0; i < m; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    int dx = get(ds, x), dy = get(ds, y);
    if (dx == dy) unusedEdges.push_back({x, y, z});
    else
    {
      ds[dx] = dy;
      a[x].push_back({y, -1});
      a[y].push_back({x, -1});
    }
  }

  dfs(1);
  for (int i = 1; i <= n; i++)
    anc[i] = i;
  for (auto [x, y, z] : unusedEdges)
    while (1)
    {
      x = get(anc, x);
      y = get(anc, y);
      if (x == y)
        break;
      int dx = depth[x], dy = depth[y];
      if (dx >= dy)
      {
        if (parEdge[x] >= 0 && ans[parEdge[x]] == oo)
          ans[parEdge[x]] = z;
        x = anc[x] = par[x];
      }
      if (dy >= dx)
      {
        if (parEdge[y] >= 0 && ans[parEdge[y]] == oo)
          ans[parEdge[y]] = z;
        y = anc[y] = par[y];
      }
    }

  long long sum = 0;
  for (int i = 0; i < k; i++)
    if (ans[i] < oo) sum += ans[i];
    else
    {
      cout << -1 << endl;
      return 0;
    }

  cout << sum << endl;
}