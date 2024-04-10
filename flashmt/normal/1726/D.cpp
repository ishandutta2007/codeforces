#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

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

const int N = 200200;

vector<pair<int, int>> a[N];
vector<int> path;

int dfs(int x, int goal, int par = -1)
{
  if (x == goal)
    return 1;
  for (auto [y, id] : a[x])
    if (y != par)
    {
      path.push_back(id);
      if (dfs(y, goal, x))
        return 1;
      path.pop_back();
    }
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      a[i].clear();
    DisjointSet ds(n);
    vector<pair<int, int>> edges;
    vector<int> nonTree;
    for (int i = 0; i < m; i++)
    {
      int x, y;
      cin >> x >> y;
      x--; y--;
      if (x > y)
        swap(x, y);
      edges.push_back({x, y});
      if (ds.join(x, y))
      {
        a[x].push_back({y, i});
        a[y].push_back({x, i});
      }
      else nonTree.push_back(i);
    }

    auto isCycle = [&]() -> bool
    {
      if (size(nonTree) < 3)
        return false;
      set<int> s;
      for (int id : nonTree)
      {
        auto [x, y] = edges[id];
        s.insert(x);
        s.insert(y);
      }
      return size(s) == 3;
    };

    string ans(m, '0');
    for (int id : nonTree)
      ans[id] = '1';
    if (isCycle())
    {
      int idToFix = nonTree[0];
      auto [x, y] = edges[idToFix];
      path.clear();
      assert(dfs(x, y));
      swap(ans[idToFix], ans[path.back()]);
    }

    cout << ans << '\n';
  }
}