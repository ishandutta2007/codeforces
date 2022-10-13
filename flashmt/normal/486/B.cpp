#include <bits/stdc++.h>
using namespace std;

int m, n, b[111][111], a[111][111];

int main()
{
  ios::sync_with_stdio(0);
  cin >> m >> n;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      cin >> b[i][j];
      
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    {
      a[i][j] = 1;
      for (int ii = 1; ii <= m; ii++) a[i][j] &= b[ii][j];
      for (int jj = 1; jj <= n; jj++) a[i][j] &= b[i][jj];
    }
  
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    {
      int bb = 0;
      for (int ii = 1; ii <= m; ii++) bb |= a[ii][j];
      for (int jj = 1; jj <= n; jj++) bb |= a[i][jj];
      if (b[i][j] != bb)
      {
        cout << "NO" << endl;
        return 0;
      }
    }
      
  cout << "YES" << endl;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      cout << a[i][j] << (j == n ? '\n' : ' ');
}