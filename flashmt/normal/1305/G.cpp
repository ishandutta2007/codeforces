#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int BIT = 18;

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
  int n;
  cin >> n;
  vector<int> cnt(1 << BIT);
  long long ans = 0;
  while (n--)
  {
    int x;
    cin >> x;
    cnt[x]++;
    ans -= x;
  }
  cnt[0]++;

  DisjointSet ds(1 << BIT);
  for (int mask = (1 << BIT) - 1; mask >= 0; mask--)
    for (int submask = mask; submask > mask / 2; submask = (submask - 1) & mask)
      if (cnt[submask] && cnt[mask - submask])
        if (ds.join(submask, mask - submask))
        {
          ans += mask * (cnt[submask] + cnt[mask - submask] - 1LL);
          cnt[submask] = cnt[mask - submask] = 1;
        }

  cout << ans << endl;
}