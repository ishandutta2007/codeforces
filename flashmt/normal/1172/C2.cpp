#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

long long power(long long x, int y)
{
  if (!y) 
    return 1;
  long long r = power(x, y / 2);
  r = r * r % BASE;
  if (y % 2)
    r = r * x % BASE;
  return r;
}

int main()
{
  int n, m, a[200200], w[200200], sumLike = 0, sumDislike = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
  {
    cin >> w[i];
    if (a[i]) sumLike += w[i];
    else sumDislike += w[i];
  }

  int sum = sumLike + sumDislike, inv[6666];
  for (int i = -m; i <= m; i++)
    inv[i + m] = power(sum + i, BASE - 2);

  int expectedLike = 0, expectedDislike = 0, f[3333][3333] = {0};
  f[0][0] = 1;
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= i; j++)
    {
      int currentSumLike = sumLike + j;
      int currentSumDislike = sumDislike - (i - j);
      if (currentSumDislike < 0)
        continue;

      if (i == m)
      {
        expectedLike = (expectedLike + 1LL * currentSumLike * f[i][j]) % BASE;
        expectedDislike = (expectedDislike + 1LL * currentSumDislike * f[i][j]) % BASE;
      }
      else 
      {
        long long each = 1LL * f[i][j] * inv[currentSumLike + currentSumDislike - sum + m] % BASE;
        f[i + 1][j + 1] = (f[i + 1][j + 1] + each * currentSumLike) % BASE;
        f[i + 1][j] = (f[i + 1][j] + each * currentSumDislike) % BASE;
      }
    }

  for (int i = 0; i < n; i++)
    if (a[i]) cout << 1LL * w[i] * power(sumLike, BASE - 2) % BASE * expectedLike % BASE << endl;
    else cout << 1LL * w[i] * power(sumDislike, BASE - 2) % BASE * expectedDislike % BASE << endl;
}