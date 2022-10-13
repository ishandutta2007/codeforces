#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
const int BASE = 998244353;

int main()
{
  int n, k, a[1010];
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);

  int f[1010][1010], last = 0;
  long long ans = 0;
  for (int dif = MAX / (k - 1); dif; dif--)
  {
    for (int j = 0; j <= n; j++)
      f[0][j] = 1;

    for (int i = 1; i <= k; i++)
    {
      f[i][0] = 0;
      for (int j = 1, jj = 0; j <= n; j++)
      {
        while (a[j - 1] - a[jj] >= dif)
          jj++;
        f[i][j] = (f[i][j - 1] + f[i - 1][jj]) % BASE;
      }
    }

    ans = (ans + 1LL * (f[k][n] - last + BASE) * dif) % BASE;
    last = f[k][n];
  }

  cout << ans << endl;
}