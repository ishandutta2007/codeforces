#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n, k, hor[555][555], ver[555][555], f[555][555][11] = {0};
  cin >> m >> n >> k;
  if (k % 2)
  {
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cout << "-1" << " \n"[j ==  n - 1];
    return 0;
  }

  k /= 2;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n - 1; j++)
      cin >> hor[i][j];
  for (int i = 0; i < m - 1; i++)
    for (int j = 0; j < n; j++)
      cin >> ver[i][j];

  for (int step = 1; step <= k; step++)
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
      {
        f[i][j][step] = oo;
        if (i + 1 < m)
          f[i][j][step] = min(f[i][j][step], f[i + 1][j][step - 1] + ver[i][j]);
        if (i)
          f[i][j][step] = min(f[i][j][step], f[i - 1][j][step - 1] + ver[i - 1][j]);
        if (j + 1 < n)
          f[i][j][step] = min(f[i][j][step], f[i][j + 1][step - 1] + hor[i][j]);
        if (j)
          f[i][j][step] = min(f[i][j][step], f[i][j - 1][step - 1] + hor[i][j - 1]);
        if (step == k)
          cout << f[i][j][step] * 2 << " \n"[j == n - 1];
      }
}