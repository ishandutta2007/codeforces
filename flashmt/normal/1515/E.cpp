#include <bits/stdc++.h>
using namespace std;

long long f[444][444], c[444][444], g[444], M;

int main()
{
  int n;
  cin >> n >> M;
  for (int i = 0; i <= 400; i++)
    for (int j = 0; j <= i; j++)
      c[i][j] = j ? (c[i - 1][j - 1] + c[i - 1][j]) % M : 1;

  g[1] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= i; j++)
      g[i] = (g[i] + c[i - 1][j - 1]) % M;

  f[1][1] = 1;
  for (int i = 2; i <= n; i++)
  {
    f[i][i] = g[i];
    for (int j = 1; j < i; j++)
      for (int ii = i - 2; ii; ii--)
      {
        int num = i - ii - 1, jj = j - num;
        if (jj >= 0 && jj <= ii)
          f[i][j] = (f[i][j] + f[ii][jj] * g[num] % M * c[j][jj]) % M;
      }

  }

  long long ans = 0;
  for (int i = 1; i <= n; i++)
    ans += f[n][i];
  ans %= M;
  cout << ans << endl;
}