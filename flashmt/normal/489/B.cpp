#include <bits/stdc++.h>
using namespace std;

int n, m, boys[111], girls[111];

int main()
{
  ios::sync_with_stdio(0);
  cin >> m;
  for (int i = 0; i < m; i++) cin >> boys[i];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> girls[i];
  
  sort(boys, boys + m);
  sort(girls, girls + n);
  
  int ans = 0;
  for (int i = 0, j = 0; i < m && j < n; i++)
  {
    while (j < n && girls[j] + 1 < boys[i]) j++;
    if (j == n) break;
    if (girls[j] >= boys[i] - 1 && girls[j] <= boys[i] + 1)
    {
      ans++;
      j++;
    }
  }
  
  cout << ans << endl;
}