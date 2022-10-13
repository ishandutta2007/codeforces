#include <bits/stdc++.h>
using namespace std;

int m, n, f[5050][5050];
string a, b;

int main()
{
  cin >> m >> n >> a >> b;
  int ans = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    {
      f[i][j] = max(0, max(f[i][j - 1], f[i - 1][j]) - 1);
      if (a[i - 1] == b[j - 1])
        f[i][j] = max(f[i][j], f[i - 1][j - 1] + 2);
      ans = max(ans, f[i][j]);
    }

  cout << ans << endl;
}