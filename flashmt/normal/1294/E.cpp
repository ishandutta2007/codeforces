#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, n;
  cin >> m >> n;
  vector<vector<int>> a(m, vector<int>(n));

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
      a[i][j]--;
    }

  int ans = 0;
  for (int j = 0; j < n; j++)
  {
    vector<int> cnt(m, 0);
    for (int i = 0; i < m; i++)
      if (a[i][j] % n == j && a[i][j] / n < m)
        cnt[(i + m - a[i][j] / n) % m]++;

    int best = m;
    for (int i = 0; i < m; i++)
      best = min(best, i + m - cnt[i]);
    ans += best;
  }

  cout << ans << endl;
}