#include <bits/stdc++.h>
using namespace std;

map <int,int> f[333];

int main()
{
  ios::sync_with_stdio(0);
  int n, l[333], c[333];
  
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> l[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  
  f[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (auto p : f[i - 1])
    {
      if (!f[i].count(p.first)) f[i][p.first] = p.second;
      else f[i][p.first] = min(f[i][p.first], p.second);      
      
      int j = __gcd(l[i], p.first);
      if (!f[i].count(j)) f[i][j] = p.second + c[i];
      else f[i][j] = min(f[i][j], p.second + c[i]);
    }
    
  cout << (f[n].count(1) ? f[n][1] : -1) << endl;
}