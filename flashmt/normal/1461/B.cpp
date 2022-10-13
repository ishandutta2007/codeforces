#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int m, n;
    string a[500];
    cin >> m >> n;
    for (int i = 0; i < m; i++)
      cin >> a[i];

    vector<vector<int>> f(m, vector<int>(n));
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
      vector<int> l(n), r(n);
      l[0] = a[i][0] == '*';
      for (int j = 1; j < n; j++)
        l[j] = a[i][j] == '*' ? l[j - 1] + 1 : 0;

      r[n - 1] = a[i][n - 1] == '*';
      for (int j = n - 2; j >= 0; j--)
        r[j] = a[i][j] == '*' ? r[j + 1] + 1 : 0;

      for (int j = 0; j < n; j++)
      {
        if (i) f[i][j] = f[i - 1][j] + 1;
        else f[i][j] = 1;
        f[i][j] = min({f[i][j], l[j], r[j]});
        ans += f[i][j];
      }
    }

    cout << ans << endl;
  }
}