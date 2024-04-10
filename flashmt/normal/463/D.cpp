#include <bits/stdc++.h>
using namespace std;

int n, m, a[5][1010], pos[5][1010], f[1010];

int main()
{
  ios::sync_with_stdio(0);
  
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
      pos[i][--a[i][j]] = j;
    }
  }
  
  f[0] = 1;
  for (int j = 1; j < n; j++)
  {
    f[j] = 1;
    int x = a[0][j];
    for (int k = 0; k < j; k++)
    {
      int y = a[0][k], ok = 1;
      for (int i = 1; i < m; i++)
        if (pos[i][y] > pos[i][x]) 
        {
          ok = 0;
          break;
        }
        
      if (ok) f[j] = max(f[j], f[k] + 1);
    }
  }
  
  int ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, f[i]);
  cout << ans << endl;
}