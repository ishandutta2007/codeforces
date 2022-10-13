#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

int n, a, b, k;
long long f[5050][5050];

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> a >> b >> k;
  
  f[0][a] = 1;
  f[0][a + 1] = BASE - 1;
  
  for (int i = 0; i <= k; i++)
    for (int j = 1; j <= n; j++)
    {
      f[i][j] = (f[i][j] + f[i][j - 1]) % BASE;
      int low = max(1, j - (abs(b - j) - 1)), high = min(n, j + (abs(b - j) - 1));
      
      if (low != j)
      {
        f[i + 1][low] = (f[i + 1][low] + f[i][j]) % BASE;
        f[i + 1][j] = (f[i + 1][j] - f[i][j] + BASE) % BASE;
      }
      
      if (high != j)
      {
        f[i + 1][j + 1] = (f[i + 1][j + 1] + f[i][j]) % BASE;
        f[i + 1][high + 1] = (f[i + 1][high + 1] - f[i][j] + BASE) % BASE;
      }
    }
    
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + f[k][i]) % BASE;
  cout << ans << endl;
}