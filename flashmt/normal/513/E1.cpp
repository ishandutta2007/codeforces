#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111000;

int n, k, a[30300], f[222][30300][2], ans[222][30300];

int main()
{
  int x;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    cin >> x;
    a[i] = a[i - 1] + x;
  }
  
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= n; j++)
      f[i][j][0] = f[i][j][1] = -oo;
  
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= n; j++)
    {
      ans[i][j] = ans[i][j - 1];
      f[i][j][0] = f[i][j - 1][0];
      f[i][j][1] = f[i][j - 1][1];
      for (int jj = 0; jj < j; jj++)
      {
        int sum = a[j] - a[jj];
        int best = max(f[i - 1][jj][1] + sum, f[i - 1][jj][0] - sum);
        if (i == 1) best = 0;
        ans[i][j] = max(ans[i][j], best);
        f[i][j][0] = max(f[i][j][0], best + sum);
        f[i][j][1] = max(f[i][j][1], best - sum);
      }
    }
    
  cout << ans[k][n] << endl;
}