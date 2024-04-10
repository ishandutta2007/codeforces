#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111000;

int n, k, a[30300], f[222][30300][4];

int main()
{
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  
  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= n; j++)
      for (int u = 0; u < 4; u++)
        f[i][j][u] = -oo;
  
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= n; j++)
    {
      int value = a[j] * (i > 1 && i < k ? 2 : 1);
      
      f[i][j][0] = max(max(f[i][j - 1][0], f[i - 1][j - 1][1]), f[i - 1][j - 1][3]) + value;
      if (i == 1) f[i][j][0] = max(f[i][j][0], value);
      
      f[i][j][1] = max(max(f[i][j - 1][1], f[i - 1][j - 1][0]), f[i - 1][j - 1][2]) - value;
      if (i == 1) f[i][j][1] = max(f[i][j][1], -value);
      
      f[i][j][2] = max(max(f[i - 1][j - 1][2], f[i][j - 1][2]), f[i - 1][j - 1][0]);
      
      f[i][j][3] = max(max(f[i - 1][j - 1][3], f[i][j - 1][3]), f[i - 1][j - 1][1]);
    }
    
  int ans = -oo;
  for (int j = k; j <= n; j++)
    ans = max(ans, max(f[k][j][0], f[k][j][1]));
  cout << ans << endl;
}