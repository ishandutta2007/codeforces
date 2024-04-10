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
    vector<int> a(n);
    int l = -1, r = -1;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (a[i])
      {
        if (l < 0)
          l = i;
        r = i;
      }
    }

    if (l < 0) cout << "0\n";
    else
    {
      int ans = 1;
      for (int i = l; i <= r; i++)
        if (!a[i])
          ans = 2;
      cout << ans << '\n';
    }
  }
}