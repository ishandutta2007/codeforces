#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vector<string> a(m);
  for (int i = 0; i < m; i++)
    cin >> a[i];

  vector<vector<int>> f(m + 1, vector<int>(n + 1));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] == 'B')
      {
        f[i][j] ^= 1;
        f[i + 1][j] ^= 1;
        f[i][j + 1] ^= 1;
        f[i + 1][j + 1] ^= 1;
      }

  int sum = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      sum += f[i][j];

  int ans = sum;
  for (int i = 1; i < m; i++)
    for (int j = 1; j < n; j++)
      ans = min(ans, sum + 3 - f[i][j] - f[i][n] - f[m][j] - f[m][n]);

  cout << ans << endl;
}