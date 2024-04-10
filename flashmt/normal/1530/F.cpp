#include <bits/stdc++.h>
using namespace std;
const int BASE = 31607;

int n, a[22][22];

int power(int x, int y)
{
  if (!y)
    return 1;
  int res = power(x, y >> 1);
  res = res * res % BASE;
  if (y & 1)
    res = res * x % BASE;
  return res;
}

int calc(int pickDia, int pickAntidia)
{
  int diaProb = 1, prob[22][22];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      prob[i][j] = a[i][j] * power(10000, BASE - 2) % BASE;
      if ((i == j && pickDia) || (i + j == n - 1 && pickAntidia))
      {
        diaProb = diaProb * prob[i][j] % BASE;
        prob[i][j] = 1;
      }
    }

  vector<int> f(1 << n, 1), rowProb(1 << n);
  for (int row = 0; row < n; row++)
  {
    rowProb[0] = 1;
    for (int col = 0; col < n; col++)
      rowProb[1 << col] = prob[row][col];
    for (int mask = 1; mask < 1 << n; mask++)
      rowProb[mask] = rowProb[mask & -mask] * rowProb[mask ^ (mask & -mask)] % BASE;
    for (int mask = 0; mask < 1 << n; mask++)
      f[mask] = f[mask] * rowProb[mask] % BASE * (1 - rowProb[(1 << n) - 1 - mask] + BASE) % BASE;
  }

  int res = 0;
  for (int mask = 0; mask < 1 << n; mask++)
    if (__builtin_popcount(mask) % 2) res = (res - f[mask] + BASE) % BASE;
    else res = (res + f[mask]) % BASE;

  res = res * diaProb % BASE;
  return res;
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  int ans = 0;
  for (int pickDia = 0; pickDia < 2; pickDia++)
    for (int pickAntidia = 0; pickAntidia < 2; pickAntidia++)
      if (pickDia == pickAntidia) ans = (ans + calc(pickDia, pickAntidia)) % BASE;
      else ans = (ans - calc(pickDia, pickAntidia) + BASE) % BASE;

  cout << (1 - ans + BASE) % BASE << endl;
}