#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int f[1010][1010][3][4];

void add(int &x, int y)
{
  x += y;
  if (x >= BASE)
    x -= BASE;
}

int main()
{
  string a, b;
  cin >> a >> b;
  int m = a.size(), n = b.size();
  a = " " + a;
  b = " " + b;

  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
    {
      for (int last = 0; last < 2; last++)
        for (int mask = 1; mask < 4; mask++)
        {
          int val = f[i][j][last][mask];
          if (!val)
            continue;
          char lastChar = (last ? b[j] : a[i]);

          if (i < m && a[i + 1] != lastChar)
            add(f[i + 1][j][0][mask | 1], val);

          if (j < n && b[j + 1] != lastChar)
            add(f[i][j + 1][1][mask | 2], val);
        }

      if (i < m)
        add(f[i + 1][j][0][1], 1);

      if (j < n)
        add(f[i][j + 1][1][2], 1);
    }

  int ans = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      for (int last = 0; last < 2; last++)
        add(ans, f[i][j][last][3]);

  cout << ans << endl;
}