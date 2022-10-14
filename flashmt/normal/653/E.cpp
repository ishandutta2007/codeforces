#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<set<int>> a(n);
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    a[--x].insert(--y);
    a[y].insert(x);
  }

  set<int> alive;
  for (int i = 1; i < n; i++)
    alive.insert(i);
  vector<int> deg(n);

  function<void(int)> dfs = [&](int x)
  {
    int last = 0;
    while (1)
    {
      auto y = alive.lower_bound(last);
      if (y == end(alive))
        break;

      last = *y + 1;
      if (!a[x].count(*y))
      {
        deg[x]++;
        alive.erase(*y);
        dfs(*y);
      }
    }
  };

  dfs(0);
  cout << (empty(alive) && deg[0] <= k && n - 1 - size(a[0]) >= k ? "possible" : "impossible") << '\n';
}