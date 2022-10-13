#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int main()
{
  int m, n;
  cin >> m >> n;

  long long f[100100][3];
  f[1][1] = 1;
  f[1][2] = 2;
  f[2][1] = 2;
  f[2][2] = 3;

  for (int i = 3; i <= m; i++)
  {
    f[i][1] = (f[i - 1][1] + f[i - 2][1]) % BASE;
    f[i][2] = (f[i - 1][2] + f[i - 2][2] - 1 + BASE) % BASE;
  }

  long long g[100100];
  g[1] = f[m][1];
  g[2] = f[m][2];
  for (int i = 3; i <= n; i++)
    g[i] = (g[i - 1] + g[i - 2] + 1 - f[m][1] + BASE) % BASE;

  cout << g[n] * 2 % BASE << endl;
}