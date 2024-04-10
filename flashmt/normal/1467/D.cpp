#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int f[5050][5050];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k, q;
  cin >> n >> k >> q;

  for (int i = 0; i < n; i++)
    f[0][i] = 1;
  for (int i = 1; i <= k; i++)
    for (int j = 0; j < n; j++)
    {
      f[i][j] = f[i - 1][j + 1];
      if (j)
        f[i][j] = (f[i][j] + f[i - 1][j - 1]) % BASE;
    }

  vector<long long> coef(n, 0);
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= k; j++)
      coef[i] = (coef[i] + 1LL * f[j][i] * f[k - j][i]) % BASE;

  vector<int> a(n);
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    ans = (ans + 1LL * a[i] * coef[i]) % BASE;
  }

  while (q--)
  {
    int i, x;
    cin >> i >> x;
    i--;
    ans = (ans + 1LL * (x + BASE - a[i]) * coef[i]) % BASE;
    a[i] = x;
    cout << ans << '\n';
  }
}