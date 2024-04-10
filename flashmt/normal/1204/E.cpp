#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244853;

int main()
{
  int m, n;
  cin >> m >> n;

  int ways[2020][2020] = {0};
  for (int i = 0; i <= 2000; i++)
    for (int j = i; j <= 2000; j++)
      if (!j) ways[i][j] = 1;
      else
      {
        if (j)
          ways[i][j] = (ways[i][j] + ways[i][j - 1]) % BASE;
        if (i)
          ways[i][j] = (ways[i][j] + ways[i - 1][j]) % BASE;
      }

  long long ans = 0;
  for (int i = 0; i <= m + n; i++)
    for (int j = 1; j <= min(i, m); j++)
    {
      int k = i - j, maxPrefix = max(0, j - k);
      if (k > n)
        continue;
      ans = (ans + 1LL * ways[k][j - 1] * ways[m - j][n - k] % BASE * maxPrefix) % BASE;
    }

  cout << ans << endl;
}