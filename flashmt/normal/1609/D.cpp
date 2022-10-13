#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  DisjointSet ds(n);
  int freeEdges = 0, comp[1010];
  for (int i = 0; i < d; i++)
  {
    int x, y;
    cin >> x >> y;
    int dx = ds.get(--x), dy = ds.get(--y);
    if (dx == dy) freeEdges++;
    else ds.join(dx, dy);

    int numComp = 0;
    for (int x = 0; x < n; x++)
      if (ds.get(x) == x)
        comp[numComp++] = ds.sz[x];

    sort(comp, comp + numComp);
    int ans = 0;
    for (int j = 1; j <= freeEdges + 1; j++)
      if (j <= numComp)
        ans += comp[numComp - j];
    cout << ans - 1 << '\n';
  }
}