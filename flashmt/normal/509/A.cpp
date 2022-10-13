#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, a[11][11];
  cin >> n;
  
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      a[i][j] = (i == 1 || j == 1 ? 1 : a[i][j - 1] + a[i - 1][j]);
  
  cout << a[n][n] << endl;
}