#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int BIT = 30;

struct DisjointSet
{
  int n;
  vector<int> ds, sz, isGood;

  DisjointSet(int n, vector<int> &isGood): n(n)
  {
    ds = sz = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
      ds[i] = i;
      sz[i] = 1;
    }
    this->isGood = isGood;
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
    isGood[dx] |= isGood[dy];
    return 1;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> a(n);
  vector<int> isEven(n);
  while (m--)
  {
    int x, y, w;
    cin >> x >> y >> w;
    a[--x].push_back({--y, w});
    a[y].push_back({x, w});
    if (w % 2 == 0)
      isEven[x] = isEven[y] = 1;
  }

  vector<DisjointSet> ds(BIT, DisjointSet(n, isEven));
  for (int x = 0; x < n; x++)
    for (auto [y, w] : a[x])
      for (int i = 0; i < BIT; i++)
        if (w >> i & 1)
          ds[i].join(x, y);

  int q;
  cin >> q;
  while (q--)
  {
    int x, y;
    cin >> x >> y;
    x--; y--;
    int ans = 2;
    for (int i = 0; i < BIT; i++)
    {
      if (i && ds[i].isGood[ds[i].get(x)])
        ans = min(ans, 1);
      if (ds[i].get(x) == ds[i].get(y))
        ans = min(ans, 0);
    }
    cout << ans << '\n';
  }
}