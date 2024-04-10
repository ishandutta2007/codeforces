#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 200200;
const int LOG = 19;

vector<pair<int, int>> a[N];
vector<tuple<int, int, int>> edges;
int ds[N], anc[N];
int depth[N], p[N][LOG], maxEdge[N][LOG], parEdgeId[N];

int get(int ds[], int x)
{
  return x == ds[x] ? x : ds[x] = get(ds, ds[x]);
}

void dfs(int x)
{
  for (int i = 0; i < LOG; i++)
    if (p[x][i] >= 0)
    {
      int y = p[x][i];
      p[x][i + 1] = p[y][i];
      maxEdge[x][i + 1] = max(maxEdge[x][i], maxEdge[y][i]);
    }

  for (auto [y, id] : a[x])
    if (y != p[x][0])
    {
      p[y][0] = x;
      maxEdge[y][0] = get<2>(edges[id]);
      parEdgeId[y] = id;
      depth[y] = depth[x] + 1;
      dfs(y);
    }
}

pair<int, int> lca(int x, int y)
{
  if (depth[x] > depth[y])
    swap(x, y);
  int curMaxEdge = 0;
  for (int i = LOG - 1; i >= 0; i--)
    if (depth[y] - (1 << i) >= depth[x])
    {
      curMaxEdge = max(curMaxEdge, maxEdge[y][i]);
      y = p[y][i];
    }
  if (x == y)
    return {x, curMaxEdge};
  for (int i = LOG - 1; i >= 0; i--)
    if (p[x][i] != p[y][i])
    {
      curMaxEdge = max({curMaxEdge, maxEdge[x][i], maxEdge[y][i]});
      x = p[x][i];
      y = p[y][i];
    }
  curMaxEdge = max({curMaxEdge, maxEdge[x][0], maxEdge[y][0]});
  return {p[x][0], curMaxEdge};
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    edges.push_back({--x, --y, z});
  }

  vector<int> edgeId(m);
  iota(begin(edgeId), end(edgeId), 0);
  sort(begin(edgeId), end(edgeId), [&](int u, int v) { return get<2>(edges[u]) < get<2>(edges[v]); });

  for (int i = 0; i < n; i++)
    ds[i] = anc[i] = i;
  vector<int> isTreeEdge(m);
  for (int i : edgeId)
  {
    auto [x, y, z] = edges[i];
    int dx = get(ds, x), dy = get(ds, y);
    if (dx != dy)
    {
      isTreeEdge[i] = 1;
      a[x].push_back({y, i});
      a[y].push_back({x, i});
      ds[dy] = dx;
    }
  }

  memset(p, -1, sizeof p);
  dfs(0);

  vector<int> ans(m, -1);
  for (int i : edgeId)
    if (!isTreeEdge[i])
    {
      auto [x, y, w] = edges[i];
      auto [z, curMaxEdge] = lca(x, y);
      ans[i] = curMaxEdge - 1;

      while (1)
      {
        x = get(anc, x);
        y = get(anc, y);
        if (x == y)
          break;
        int dx = depth[x], dy = depth[y];
        if (dx >= dy)
        {
          ans[parEdgeId[x]] = w - 1;
          x = anc[x] = p[x][0];
        }
        if (dy >= dx)
        {
          ans[parEdgeId[y]] = w - 1;
          y = anc[y] = p[y][0];
        }
      }
    }

  for (int x : ans)
    cout << x << ' ';
}