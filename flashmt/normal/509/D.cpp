#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 40;

int main()
{
  ios::sync_with_stdio(0);
  int m, n;
  long long a[111][111], row[111], col[111];
  
  cin >> m >> n;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      cin >> a[i][j];
      
  for (int j = 1; j <= n; j++) 
    col[j] = a[1][j];
  for (int i = 2; i <= m; i++)
    row[i] = a[i][1] - col[1];
  
  long long k = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      k = __gcd(k, abs(a[i][j] - row[i] - col[j]));
      
  if (!k) k = oo;
  else
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        if (a[i][j] >= k)
        {
          cout << "NO\n";
          return 0;
        }
        
  cout << "YES\n";
  cout << k << endl;
  for (int i = 1; i <= m; i++) 
    cout << (row[i] + k) % k << (i == m ? '\n' : ' ');
  for (int j = 1; j <= n; j++)
    cout << (col[j] + k) % k << (j == n ? '\n' : ' ');
}