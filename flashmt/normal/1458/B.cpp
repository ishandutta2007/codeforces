#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000;
const int oo = 27081993;

int main()
{
  int n, a[111], b[111], f[111][10010], sumA = 0, sumB = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i] >> b[i];
    sumA += a[i];
    sumB += b[i];
  }

  for (int j = 0; j <= n; j++)
    for (int k = 0; k <= MAX; k++)
      f[j][k] = -oo;

  f[0][0] = 0;
  for (int i = 1, sum = 0; i <= n; i++)
  {
    sum += a[i];
    for (int j = i; j; j--)
      for (int k = sum; k >= a[i]; k--)
        f[j][k] = max(f[j][k], f[j - 1][k - a[i]] + b[i]);
  }

  for (int i = 1; i <= n; i++)
  {
    int ans = 0;
    for (int j = 0; j <= MAX; j++)
      if (f[i][j] >= 0)
      {
        int toFill = j - f[i][j];
        ans = max(ans, f[i][j] * 2 + min(sumB - f[i][j], toFill * 2));
      }

    cout << fixed << setprecision(2) << ans * 0.5 << ' ';
  }
}