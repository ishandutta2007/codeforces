#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, a[777];
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  a[0] = a[n + 1] = 1;

  int f[777][777] = {0}, g[777][777] = {0};
  for (int i = 0; i <= n; i++)
    f[i + 1][i] = g[i + 1][i] = 1;

  for (int len = 1; len <= n; len++)
    for (int i = 1; i + len - 1 <= n; i++)
    {
      int j = i + len - 1;
      for (int k = i; k <= j && (!f[i][j] || !g[i][j]); k++)
        if (g[i][k - 1] && f[k + 1][j])
        {
          if (gcd(a[k], a[i - 1]) > 1 || len == n)
            f[i][j] = 1;
          if (gcd(a[k], a[j + 1]) > 1 || len == n)
            g[i][j] = 1;
        }
    }

  cout << (f[1][n] || g[1][n] ? "Yes" : "No") << endl;
}