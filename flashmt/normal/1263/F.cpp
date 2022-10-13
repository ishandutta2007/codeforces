#include <bits/stdc++.h>
using namespace std;

int m, n, from[2020], to[2020], cost[2020][2020], cnt[2020][2020];
vector<int> a[2020];

void dfs(int x, int par)
{
  // cout << x << ' ' << par << endl;
  for (int y : a[x])
    if (y != par)
    {
      dfs(y, x);
      from[x] = min(from[x], from[y]);
      to[x] = max(to[x], to[y]);
    }

  if (x > 1)
    cnt[from[x]][to[x]]++;
}

void process()
{
  memset(cnt, 0, sizeof cnt);
  dfs(1, 0);
  for (int len = 1; len <= m; len++)
    for (int i = 1; i + len - 1 <= m; i++)
    {
      int j = i + len - 1;
      cnt[i][j] += cnt[i][j - 1] + cnt[i + 1][j] - cnt[i + 1][j - 1];
      cost[i][j] = max(cost[i][j], cnt[i][j]);
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> m;
  for (int _ = 0; _ < 2; _++)
  {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      a[i].clear();
      from[i] = m + 1;
      to[i] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
      int x;
      cin >> x;
      a[x].push_back(i);
      a[i].push_back(x);
    }
    for (int i = 1; i <= m; i++)
    {
      int x;
      cin >> x;
      from[x] = to[x] = i;
    }
    process();
  }

  vector<int> f(m + 1, 0);
  for (int i = 1; i <= m; i++)
    for (int j = 0; j < i; j++)
      f[i] = max(f[i], f[j] + cost[j + 1][i]);
  cout << f[m] << endl;
}