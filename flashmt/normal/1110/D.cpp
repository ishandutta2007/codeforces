#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, a[1000100] = {0}, x;
  cin >> n >> m;
  while (n--)
  {
    cin >> x;
    a[x]++;
  }

  int f[1000100][3][3] = {0};
  for (int i = 1; i <= m; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        for (int p = 0; p < 3; p++)
          if (a[i] >= j + k + p && a[i + 1] >= k + p && a[i + 2] >= p)
            f[i + 1][k][p] = max(f[i + 1][k][p], f[i][j][k] + p + (a[i] - j - k - p) / 3);

  cout << f[m + 1][0][0] << endl;
}