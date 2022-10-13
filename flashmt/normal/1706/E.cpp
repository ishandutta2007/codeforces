#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int LOG = 19;

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

template<typename T, class F = function<T(const T&, const T&)>>
struct SparseTable
{
  int n;
  vector<vector<T>> mat;
  F func;

  SparseTable(const vector<T>& a, const F& f) : func(f)
  {
    n = int(a.size());
    int maxLog = 32 - __builtin_clz(n);
    mat.resize(maxLog);
    mat[0] = a;
    for (int j = 1; j < maxLog; j++)
    {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++)
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
    }
  }

  T get(int from, int to)
  {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 31 - __builtin_clz(to - from + 1);
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};


vector<vector<pair<int, int>>> a;
vector<int> depth;
vector<vector<int>> p, maxEdge;

void dfs(int x)
{
  for (int i = 0; i < LOG; i++)
    if (p[x][i] >= 0)
    {
      p[x][i + 1] = p[p[x][i]][i];
      maxEdge[x][i + 1] = max(maxEdge[x][i], maxEdge[p[x][i]][i]);
    }

  for (auto [y, w] : a[x])
    if (y != p[x][0])
    {
      depth[y] = depth[x] + 1;
      p[y][0] = x;
      maxEdge[y][0] = w;
      dfs(y);
    }
}

int lca(int x, int y)
{
  if (depth[x] > depth[y])
    swap(x, y);
  int res = -1;
  for (int i = LOG - 1; i >= 0; i--)
    if (depth[y] - (1 << i) >= depth[x])
    {
      res = max(res, maxEdge[y][i]);
      y = p[y][i];
    }

  if (x == y)
    return res;
  for (int i = LOG - 1; i >= 0; i--)
    if (p[x][i] != p[y][i])
    {
      res = max({res, maxEdge[x][i], maxEdge[y][i]});
      x = p[x][i];
      y = p[y][i];
    }

  res = max({res, maxEdge[x][0], maxEdge[y][0]});
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m, q;
    cin >> n >> m >> q;
    a.assign(n, vector<pair<int, int>>());
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
    }

    p.assign(n, vector<int>(LOG, -1));
    maxEdge.assign(n, vector<int>(LOG, -1));
    depth.assign(n, 0);
    dfs(0);

    vector<int> f(n - 1);
    for (int i = 0; i < n - 1; i++)
      f[i] = lca(i, i + 1);
    SparseTable<int> st(f, [](int u, int v) { return max(u, v); });

    while (q--)
    {
      int l, r;
      cin >> l >> r;
      l--; r--;
      cout << (l == r ? 0 : st.get(l, r - 1) + 1) << ' ';
    }
    cout << '\n';
  }
}