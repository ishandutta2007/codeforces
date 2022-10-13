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
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a)
      cin >> x;
    for (int &x : b)
      cin >> x;

    DisjointSet ds(n);
    for (int i = 0; i < n; i++)
      ds.join(--a[i], --b[i]);

    vector<int> comps;
    for (int i = 0; i < n; i++)
      if (ds.get(i) == i && ds.sz[i] > 1)
        comps.push_back(ds.sz[i] / 2);

    sort(begin(comps), end(comps));
    long long ans = 0;
    int v = n;
    for (int x : comps)
    {
      for (int i = 1; i < x; i++)
        ans += i * 4;
      v -= (x - 1) * 2;
      ans += (v - 1LL) * x * 2;
      v -= 2;
    }
    cout << ans << '\n';
  }
}