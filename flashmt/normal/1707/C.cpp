#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int LOG = 18;
const int N = 1e5 + 5;

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

int n, p[N][LOG], depth[N], cnt[N], dfsCount, preDfs[N], postDfs[N];
vector<int> a[N];

void dfs(int x)
{
  preDfs[x] = ++dfsCount;
  for (int i = 0; i < LOG; i++)
    if (p[x][i] >= 0)
      p[x][i + 1] = p[p[x][i]][i];

  for (int y : a[x])
    if (y != p[x][0])
    {
      p[y][0] = x;
      depth[y] = depth[x] + 1;
      dfs(y);
    }
  postDfs[x] = dfsCount;
}

int lca(int x, int y)
{
  if (depth[x] > depth[y])
    swap(x, y);
  for (int i = LOG - 1; i >= 0; i--)
    if (depth[y] - (1 << i) >= depth[x])
      y = p[y][i];
  if (x == y)
    return x;
  for (int i = LOG - 1; i >= 0; i--)
    if (p[x][i] != p[y][i])
    {
      x = p[x][i];
      y = p[y][i];
    }
  return p[x][0];
}

int getKthAncestor(int x, int k)
{
  for (int i = 0; i < LOG; i++)
    if (k >> i & 1)
      x = p[x][i];
  return x;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m;
  cin >> n >> m;
  DisjointSet ds(n);
  vector<pair<int, int>> badEdges;
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    x--; y--;
    if (ds.join(x, y))
    {
      a[x].push_back(y);
      a[y].push_back(x);
    }
    else badEdges.push_back({x, y});
  }

  memset(p, -1, sizeof p);
  dfs(0);
  for (auto [x, y] : badEdges)
  {
    if (depth[x] > depth[y])
      swap(x, y);
    int u = lca(x, y);
    if (u == x)
    {
      // z is direct child of x that contains y
      int z = getKthAncestor(y, depth[y] - depth[x] - 1);
      cnt[1]++;
      cnt[preDfs[z]]--;
      cnt[postDfs[z] + 1]++;
    }
    else
    {
      cnt[preDfs[x]]++;
      cnt[postDfs[x] + 1]--;
    }

    cnt[preDfs[y]]++;
    cnt[postDfs[y] + 1]--;
  }

  for (int i = 1; i <= n; i++)
    cnt[i] += cnt[i - 1];

  for (int i = 0; i < n; i++)
    cout << (cnt[preDfs[i]] == size(badEdges));
  cout << endl;
}