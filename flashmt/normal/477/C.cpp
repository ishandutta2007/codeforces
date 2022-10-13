#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int f[2020][2020], l[2020];

int main()
{
  ios::sync_with_stdio(0);
  string s, p;
  cin >> s >> p;
  int n = s.size(), m = p.size();
  s = "$" + s;
  p = "$" + p;
    
  for (int i = 1; i <= n; i++)
  {
    int j = m;
    l[i] = i;
    while (l[i] > 0)
    {
      if (s[l[i]] == p[j]) j--;
      if (!j) break;
      l[i]--;
    }
  }
  
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) 
      f[i][j] = -oo;
  f[0][0] = 0;
  
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= i; j++)
    {
      f[i][j] = f[i - 1][j];
      if (j) f[i][j] = max(f[i][j], f[i - 1][j - 1]);
      if (l[i] && j >= i - l[i] + 1 - m)
        f[i][j] = max(f[i][j], f[l[i] - 1][j - (i - l[i] + 1 - m)] + 1);
    }
    
  for (int i = 0; i <= n; i++) cout << f[n][i] << ' ';
}