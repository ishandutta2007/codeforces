#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

long long power(int x, int y)
{
  if (!y)
    return 1;
  long long res = power(x, y / 2);
  res = res * res % BASE;
  if (y % 2)
    res = res * x % BASE;
  return res;
}

int main()
{
  int n, m, x, y, a[18][18] = {0};
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> x >> y;
    --x;
    --y;
    a[x][y] = a[y][x] = 1;
  }

  int hasEdge[1 << 18] = {0};
  for (int mask = 0; mask < 1 << n; mask++)
    for (int i = 0; i < n; i++)
      if (mask >> i & 1)
        for (int j = i + 1; j < n; j++)
          if ((mask >> j & 1) && a[i][j])
            hasEdge[mask] = 1;

  int f[1 << 18] = {0};
  f[0] = 1;
  for (int mask = 1; mask < 1 << n; mask++)
    for (int submask = mask; submask; submask = (submask - 1) & mask)
      if (!hasEdge[submask])
      {
        if (__builtin_popcount(submask) % 2)
        {
          f[mask] += f[mask ^ submask];
          if (f[mask] >= BASE)
            f[mask] -= BASE;
        }
        else
        {
          f[mask] -= f[mask ^ submask];
          if (f[mask] < 0)
            f[mask] += BASE;
        }
      }

  cout << 1LL * f[(1 << n) - 1] * m % BASE * power(2, BASE - 2) % BASE << endl;
}