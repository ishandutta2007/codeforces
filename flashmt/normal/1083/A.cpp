#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int n, w[300300];
vector<pair<int, int>> a[300300];
long long f[300300], ans = -oo;

void dfs(int x, int par)
{
  long long max2 = 0;
  for (auto u : a[x])
  {
    int y = u.first, c = u.second;
    if (y == par)
      continue;
    dfs(y, x);
    if (f[y] - c > f[x])
    {
      max2 = f[x];
      f[x] = f[y] - c;
    }
    else max2 = max(max2, f[y] - c);
  }

  f[x] += w[x];
  ans = max(ans, max2 + f[x]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  for (int i = 1; i < n; i++)
  {
    int x, y, c;
    cin >> x >> y >> c;
    a[x].push_back({y, c});
    a[y].push_back({x, c});
  }

  dfs(1, 0);
  cout << ans << endl;
}