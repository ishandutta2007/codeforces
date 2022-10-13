#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, k;
  cin >> m >> n >> k;
  int ans = 0;
  while (k--)
  {
    if (m == 1 || n == 1) ans += max(m, n);
    else ans += (m + n - 2) * 2;
    m -= 4;
    n -= 4;
  }
  cout << ans << endl;
}