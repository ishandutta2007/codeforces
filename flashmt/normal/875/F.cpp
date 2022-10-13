#include <bits/stdc++.h>
using namespace std;

struct DisjointSet
{
  int n;
  vector<int> ds, sz, hasCycle;

  DisjointSet(int n): n(n)
  {
    ds = sz = hasCycle = vector<int>(n);
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
    hasCycle[dx] |= hasCycle[dy];
    return 1;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  DisjointSet ds(n);
  vector<vector<pair<int, int>>> edges(1e4 + 5);
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    cin >> x >> y >> w;
    edges[w].push_back({--x, --y});
  }

  int ans = 0;
  for (int w = 1e4; w; w--)
    for (auto [x, y] : edges[w])
    {
      int dx = ds.get(x), dy = ds.get(y);
      if (dx != dy)
      {
        if (!ds.hasCycle[dx] || !ds.hasCycle[dy])
        {
          ds.join(dx, dy);
          ans += w;
        }
      }
      else if (!ds.hasCycle[dx])
      {
        ds.hasCycle[dx] = 1;
        ans += w;
      }
    }

  cout << ans << endl;
}