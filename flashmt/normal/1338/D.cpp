#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  vector<vector<int>> f(n, vector<int>(2));
  int ans = 0;

  function<void(int, int)> dfs = [&](int x, int par)
  {
    if (par >= 0)
      a[x].erase(find(begin(a[x]), end(a[x]), par));
    f[x][1] = size(a[x]);
    for (int y : a[x])
      if (y != par)
      {
        dfs(y, x);

        ans = max(ans, f[x][1] + max(f[y][0], f[y][1]) - 1 + (par >= 0));
        ans = max(ans, f[x][0] + f[y][1]);

        f[x][0] = max(f[x][0], f[y][1] + 1);
        f[x][1] = max(f[x][1], max(f[y][0], f[y][1]) + int(size(a[x])) - 1);
      }

    ans = max(ans, f[x][0]);
    ans = max(ans, f[x][1] + (par >= 0));
  };

  dfs(0, -1);
  cout << ans << endl;
}