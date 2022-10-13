#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int n, m, k;
long long f[5050][5050];

long long power(long long x, long long y)
{
  if (!y)
    return 1;
  long long res = power(x, y >> 1);
  res = res * res % BASE;
  if (y & 1)
    res = res * x % BASE;
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  f[0][0] = 1;
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= i; j++)
      f[i][j] = (f[i - 1][j] * j + f[i - 1][j - 1] * (n - j + 1)) % BASE;

  long long ans = 0;
  for (int i = 1; i <= k; i++)
    ans = (ans + f[k][i] * power(power(m, i), BASE - 2)) % BASE;
  cout << ans << endl;
}