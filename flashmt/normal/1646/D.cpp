#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  if (n == 2)
  {
    cout << 2 << ' ' << 2 << endl;
    cout << 1 << ' ' << 1 << endl;
    return 0;
  }

  vector<vector<pair<int, int>>> f(n);
  function<void(int, int)> dfs = [&](int x, int par)
  {
    f[x] = {{0, -1}, {1, -int(size(a[x]))}};
    for (int y : a[x])
      if (y != par)
      {
        dfs(y, x);
        auto fy = max(f[y][0], f[y][1]);
        f[x][0].first += fy.first;
        f[x][0].second += fy.second;
        f[x][1].first += f[y][0].first;
        f[x][1].second += f[y][0].second;
      }
  };

  dfs(0, -1);
  vector<int> picked(n);
  function<void(int, int)> assign = [&](int x, int par)
  {
    for (int y : a[x])
      if (y != par)
      {
        picked[y] = !picked[x] && f[y][1] > f[y][0];
        assign(y, x);
      }
  };

  picked[0] = f[0][1] > f[0][0];
  assign(0, -1);

  auto ans = max(f[0][0], f[0][1]);
  cout << ans.first << ' ' << -ans.second << endl;
  for (int i = 0; i < n; i++)
    cout << (picked[i] ? size(a[i]) : 1) << " \n"[i == n - 1];
}