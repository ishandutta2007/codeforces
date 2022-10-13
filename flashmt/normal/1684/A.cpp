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
    int n;
    cin >> n;
    if (n < 100) cout << n % 10 << '\n';
    else
    {
      int x = 9;
      while (n)
      {
        x = min(x, n % 10);
        n /= 10;
      }
      cout << x << '\n';
    }
  }
}