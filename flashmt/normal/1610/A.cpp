#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int m, n, ans;
    cin >> m >> n;
    if (m == 1 && n == 1) ans = 0;
    else if (min(m, n) == 1) ans = 1;
    else ans = 2;
    cout << ans << '\n';
  }
}