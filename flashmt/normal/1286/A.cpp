#include <bits/stdc++.h>
using namespace std;

int n, a[111], flag[111], f[111][111][111][2];

void update(int &x, int y)
{
  if (x > y)
    x = y;
}

int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    flag[a[i]] = 1;
  }

  int odd = 0, even = 0;
  for (int i = 1; i <= n; i++)
    if (!flag[i])
    {
      if (i % 2) odd++;
      else even++;
    }

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++)
        for (int p = 0; p < 2; p++)
          f[i][j][k][p] = n - 1;

  if (a[1]) f[1][0][0][a[1] % 2] = 0;
  else f[1][0][1][0] = f[1][1][0][1] = 0;

  for (int i = 2; i <= n; i++)
    for (int j = 0; j <= odd; j++)
      for (int k = 0; k <= even; k++)
        for (int p = 0; p < 2; p++)
          if (a[i]) update(f[i][j][k][a[i] % 2], f[i - 1][j][k][p] + (a[i] % 2 ^ p));
          else
          {
            if (j)
              update(f[i][j][k][1], f[i - 1][j - 1][k][p] + (p ^ 1));
            if (k)
              update(f[i][j][k][0], f[i - 1][j][k - 1][p] + p);
          }

  cout << min(f[n][odd][even][0], f[n][odd][even][1]) << endl;
}