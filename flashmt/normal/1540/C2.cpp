#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;
const int A = 100;

int n, c[111], b[111], q, sumB[111], f[111][10100], ans[111];

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> c[i];
  for (int i = 0; i < n - 1; i++)
  {
    cin >> b[i];
    if (i)
      b[i] += b[i - 1];
    sumB[i] = b[i];
    if (i)
      sumB[i] += sumB[i - 1];
  }

  int lower = -(sumB[n - 2] / n);
  for (int x0 = lower; x0 <= lower + A; x0++)
  {
    memset(f, 0, sizeof f);
    for (int i = max(0, x0); i <= c[0]; i++)
      f[0][i] = 1;

    for (int i = 1; i < n; i++)
    {
      for (int sum = 0; sum <= i * A; sum++)
        if (f[i - 1][sum])
        {
          int minNewSum = max(sum, x0 * (i + 1) + sumB[i - 1]);
          int maxNewSum = sum + c[i];
          if (minNewSum <= maxNewSum)
          {
            f[i][minNewSum] = (f[i][minNewSum] + f[i - 1][sum]) % BASE;
            f[i][maxNewSum + 1] = (f[i][maxNewSum + 1] - f[i - 1][sum] + BASE) % BASE;
          }
        }

      for (int sum = 1; sum <= n * A; sum++)
        f[i][sum] = (f[i][sum] + f[i][sum - 1]) % BASE;
    }

    for (int i = 0; i <= n * A; i++)
      ans[x0 - lower] = (ans[x0 - lower] + f[n - 1][i]) % BASE;
  }

  long long allWays = accumulate(c, c + n, 1LL, [](long long u, int v) { return u * (v + 1) % BASE; });

  cin >> q;
  while (q--)
  {
    int x;
    cin >> x;
    if (x > lower + A) cout << 0 << '\n';
    else if (x < lower) cout << allWays << '\n';
    else cout << ans[x - lower] << '\n';
  }
}