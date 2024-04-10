#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, x;
  vector <int> a[4];
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> x;
    a[x].push_back(i);
  }
  
  int ans = min(a[1].size(), min(a[2].size(), a[3].size()));
  cout << ans << endl;
  for (int i = 0; i < ans; i++)
    cout << a[1][i] << ' ' << a[2][i] << ' ' << a[3][i] << endl;
}