#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, m, k, a[1010], ans = 0;
  cin >> n >> m >> k;
  for (int i = 0; i <= m; i++) cin >> a[i];
  
  for (int i = 0; i < m; i++)
    ans += __builtin_popcount(a[m] ^ a[i]) <= k;
  
  cout << ans << endl;
}