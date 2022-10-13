#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  double a[18][18];

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  double f[1 << 18] = {0};
  f[(1 << n) - 1] = 1;
  for (int mask = (1 << n) - 1; mask; mask--)
  {
    int num = __builtin_popcount(mask);
    if (num < 2)
      continue;

    int pairs = num * (num - 1) / 2;
    for (int i = 0; i < n; i++)
      if (mask >> i & 1)
        for (int j = i + 1; j < n; j++)
          if (mask >> j & 1)
          {
            f[mask ^ 1 << i] += f[mask] * a[j][i] / pairs;
            f[mask ^ 1 << j] += f[mask] * a[i][j] / pairs;
          }
  }

  for (int i = 0; i < n; i++)
    cout << fixed << setprecision(9) << f[1 << i] << ' ';
}