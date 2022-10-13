#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
  ios::sync_with_stdio(0);
  int n, k, a[111], used[111] = {0};
  vector <int> b[111];
  
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  
  int minA = oo;
  for (int i = 1; i <= n; i++) minA = min(minA, a[i]);
  
  
  
  for (int c = 1; c <= k; c++)
    for (int i = 1; i <= n; i++)
      if (a[i])
      {
        used[c] = 1;
        b[i].push_back(c);
        a[i]--;
      }
      
  if (minA > k)
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < minA - k; j++)
      {
        b[i].push_back(1);
        a[i]--;
      }
  
  for (int c = 1; c <= k; c++)
    if (!used[c] || c <= minA)
    {
      for (int i = 1; i <= n; i++)
        if (a[i])
        {
          b[i].push_back(c);
          a[i]--;
        }
    }
    
  for (int i = 1; i <= n; i++)
    if (a[i])
    {
      cout << "NO\n";
      return 0;
    }
  
  cout << "YES\n";
  for (int i = 1; i <= n; i++)
  {
    for (auto j : b[i]) cout << j << ' ';
    cout << '\n';
  }
}