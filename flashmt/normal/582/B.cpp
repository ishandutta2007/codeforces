#include <bits/stdc++.h>
using namespace std;

int n, T, f[222][111], g[111][111], a[111], cnt[333];

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> T;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    cnt[a[i]]++;
  }

  int m = min(n, T);
  for (int i = 1; i <= m * 2; i++)
    for (int j = 1; j <= n; j++)
    {
      f[i][j] = 1;
      for (int k = 1; k <= n; k++)
        if (a[k] <= a[j])
        {
          if (k < j)
            f[i][j] = max(f[i][j], f[i][k] + 1);
          f[i][j] = max(f[i][j], f[i - 1][k] + 1);
        }
    }

  for (int i = 1; i <= m; i++)
    for (int j = n; j; j--)
    {
      g[i][j] = 1;
      for (int k = 1; k <= n; k++)
        if (a[j] <= a[k])
        {
          if (k > j)
            g[i][j] = max(g[i][j], g[i][k] + 1);
          g[i][j] = max(g[i][j], g[i - 1][k] + 1);
        }
    }

  int ans = 0;
  if (T <= m * 2)
  {
    for (int i = 1; i <= n; i++)
      ans = max(ans, f[T][i]);
  }
  else
  {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        for (int k = 1; k <= n; k++)
          if (a[i] <= a[j] && a[j] <= a[k])
            ans = max(ans, f[m][i] + g[m][k] + (T - m * 2) * cnt[a[j]]);
  }

  cout << ans << endl;
}