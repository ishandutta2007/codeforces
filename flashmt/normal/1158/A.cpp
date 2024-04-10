#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, m, b[100100], g[100100];

  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> b[i];
  sort(b, b + n);

  for (int i = 0; i < m; i++)
    cin >> g[i];
  sort(g, g + m);

  if (b[n - 1] > g[0]) cout << -1 << endl;
  else
  {
    int cnt = 0;
    long long ans = 0;
    for (int i = 0; i < m; i++)
      if (g[i] > b[n - 1])
      {
        cnt++;
        ans += g[i];
      }

    for (int i = n - 1; i >= 0; i--)
    {
      int use = min(cnt, m - 1);
      cnt -= use;
      ans += 1LL * b[i] * (m - use);  
    }

    cout << ans << endl;
  }
}