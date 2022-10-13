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
    vector<string> s(n);
    for (int i = 0; i < n; i++)
      cin >> s[i];

    DisjointSet ds(n);

    vector<pair<int, int>> ans;
    for (int d = 1; d < n; d++)
      for (int i = 0; i + d < n; i++)
      {
        int j = i + d;
        if (s[i][d] == '1' && ds.join(i, j))
        {
          ans.push_back({i, j});
          vector<int> nodes;
          for (int k = i + 1; k < j; k++)
            if (ds.join(i, k))
              nodes.push_back(k);

          for (int k = 0, last = j; k < size(nodes); k += 2)
          {
            ans.push_back({last, nodes[k]});
            last = nodes[k];
          }

          for (int k = 1, last = i; k < size(nodes); k += 2)
          {
            ans.push_back({last, nodes[k]});
            last = nodes[k];
          }
        }
      }

    assert(size(ans) == n - 1);
    for (auto [x, y] : ans)
      cout << x + 1 << ' ' << y + 1 << endl;
  }
}