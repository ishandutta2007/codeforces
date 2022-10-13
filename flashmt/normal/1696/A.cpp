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
    int n, z;
    cin >> n >> z;
    int ans = 0;
    while (n--)
    {
      int x;
      cin >> x;
      ans = max(ans, x | z);
    }
    cout << ans << endl;
  }
}