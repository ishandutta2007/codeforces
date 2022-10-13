#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;
const int Z = 2020;

int n, m, a[2020];
long long f[2020][4040];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  if (m == 1)
  {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  f[0][Z] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = -i + Z; j <= i + Z; j++)
    {
      int ii = i % n + 1;
      if (a[ii] == a[i]) f[i][j] = (f[i][j] + f[i - 1][j] * m) % BASE;
      else
      {
        f[i][j - 1] = (f[i][j - 1] + f[i - 1][j]) % BASE;
        f[i][j] = (f[i][j] + f[i - 1][j] * (m - 2)) % BASE;
        f[i][j + 1] = (f[i][j + 1] + f[i - 1][j]) % BASE;
      }
    }

  long long ans = 0;
  for (int j = 1; j <= n; j++)
    ans = (ans + f[n][j + Z]) % BASE;
  cout << ans << endl;
}