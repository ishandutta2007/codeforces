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
    long long n;
    cin >> n;
    if (n % 2) cout << 2 << '\n';
    else
    {
      long long p = 1, x = n;
      while (x % 2 == 0)
      {
        x /= 2;
        p *= 2;
      }
      p *= 2;

      if (x > 1 && n * 2 / x >= x + 1) cout << x << '\n';
      else if (n * 2 / p >= p + 1) cout << p << '\n';
      else cout << -1 << '\n';
    }
  }
}