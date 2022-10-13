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
    long long a, b, c;
    cin >> a >> b >> c;
    cout << (b << 30) + a << ' ' << b << ' ' << c << '\n';
  }
}