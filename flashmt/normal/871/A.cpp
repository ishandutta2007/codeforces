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
    if (n % 2 == 0) cout << (n >= 4 ? n / 4 : -1) << '\n';
    else if (n % 4 == 1) cout << (n >= 9 ? n / 4 - 1 : -1) << '\n';
    else cout << (n >= 15 ? n / 4 - 1 : -1) << '\n';
  }
}