#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

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
  int n, k;
  cin >> n >> k;
  long long c[444][444] = {0};
  long long f[444][444] = {0}; // i numbers, j swaps
  long long g[444][444] = {0}; // p[i] != i

  for (int i = 0; i <= 400; i++)
    for (int j = 0; j <= i; j++)
      c[i][j] = j ? (c[i - 1][j - 1] + c[i - 1][j]) % BASE : 1;

  for (int i = 1; i <= k * 2; i++)
  {
    f[i][0] = 1;
    for (int j = 1; j <= i; j++)
      f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] * (i - 1)) % BASE;
  }

  for (int i = 1; i <= k * 2; i++)
    for (int j = 0; j <= i; j++)
      for (int fixed = 0; fixed <= i; fixed++)
      {
        long long ways = f[i - fixed][j] * c[i][fixed] % BASE;
        g[i][j] = (g[i][j] + (fixed % 2 ? -1 : 1) * ways + BASE) % BASE;
      }

  long long cn[444] = {1};
  for (int i = 1; i <= k * 2 && i <= n; i++)
    cn[i] = cn[i - 1] * (n - i + 1) % BASE * power(i, BASE - 2) % BASE;

  long long ans[222] = {1};
  for (int j = 1; j <= k; j++)
  {
    for (int i = 1; i <= j * 2; i++)
      ans[j] = (ans[j] + cn[i] * g[i][j]) % BASE;
    if (j >= 2)
      ans[j] = (ans[j] + ans[j - 2]) % BASE;
    cout << ans[j] << " \n"[j == k];
  }
}