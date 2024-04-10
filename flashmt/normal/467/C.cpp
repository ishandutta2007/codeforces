#include <bits/stdc++.h>
using namespace std;

int n, m, k;
long long a[5050], f[5050][5050];

int main()
{
  ios::sync_with_stdio(0);
  
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) 
  {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  
  for (int i = m; i <= n; i++)
    for (int j = 1; j <= k; j++)
      f[i][j] = max(f[i - 1][j], f[i - m][j - 1] + a[i] - a[i - m]);
      
  cout << f[n][k] << endl;
}