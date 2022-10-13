#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, c[555], f[555][555];

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> c[i];
    f[i][i] = 1;
    if (i)
      f[i - 1][i] = 1 + (c[i - 1] != c[i]);
  } 

  for (int l = 3; l <= n; l++)
    for (int i = 0; i + l <= n; i++)
    {
      int j = i + l - 1;
      f[i][j] = l;
      for (int k = i + 1; k <= j; k++)
        f[i][j] = min(f[i][j], f[i][k - 1] + f[k][j]);
      if (c[i] == c[j])
        f[i][j] = min(f[i][j], f[i + 1][j - 1]);
    }

  cout << f[0][n - 1] << endl;
}