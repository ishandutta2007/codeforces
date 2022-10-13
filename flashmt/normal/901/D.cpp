#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int N = 1e5 + 5;
const int M = 1e5 + 5;

struct DisjointSet
{
  int n;
  vector<int> ds, sz;

  DisjointSet(int n): n(n)
  {
    ds = sz = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
      ds[i] = i;
      sz[i] = 1;
    }
  }

  int get(int x)
  {
    return x == ds[x] ? x : ds[x] = get(ds[x]);
  }

  int join(int x, int y)
  {
    int dx = get(x), dy = get(y);
    if (dx == dy)
      return 0;
    if (sz[dx] < sz[dy])
      swap(dx, dy);
    ds[dy] = dx;
    sz[dx] += sz[dy];
    return 1;
  }
};

vector<pair<int, int>> a[N];
long long ans[M], c[N], cur[N];
int depth[N];

void dfs(int x, int par = -1)
{
  for (auto [y, id] : a[x])
    if (y != par)
    {
      depth[y] = depth[x] + 1;
      dfs(y, x);
      ans[id] += c[y] - cur[y];
      cur[x] += c[y] - cur[y];
      cur[y] = c[y];
    }
}

int go(int x, int par, int goal)
{
  if (x == goal)
    return 1;

  for (auto [y, id] : a[x])
    if (y != par && go(y, x, goal))
    {
      ans[id] += c[y] - cur[y];
      cur[x] += c[y] - cur[y];
      cur[y] = c[y];
      return 1;
    }

  return 0;
}

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> c[i];
  vector<tuple<int, int, int>> extraEdges;
  DisjointSet ds(n);
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    x--; y--;
    if (ds.join(x, y))
    {
      a[x].push_back({y, i});
      a[y].push_back({x, i});
    }
    else extraEdges.push_back({x, y, i});
  }

  dfs(0);
  if (cur[0] != c[0])
  {
    // find an odd cycle to fix
    int u = -1, v = -1, edgeId = -1;
    for (auto [x, y, id] : extraEdges)
      if (depth[x] % 2 == depth[y] % 2)
      {
        u = x;
        v = y;
        edgeId = id;
        break;
      }

    if (u >= 0)
    {
      memset(cur, 0, sizeof cur);
      memset(ans, 0, sizeof ans);
      dfs(u);
      long long need = (c[u] - cur[u]) / 2;
      ans[edgeId] = need;
      cur[u] += need;
      cur[v] += need;
      go(u, -1, v);
    }
  }

  for (int i = 0; i < n; i++)
    if (c[i] != cur[i])
    {
      cout << "NO" << endl;
      return 0;
    }

  cout << "YES" << endl;
  for (int i = 0; i < m; i++)
    cout << ans[i] << '\n';
}