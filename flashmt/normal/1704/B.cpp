#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;
    int ans = 0;
    for (int i = 0; i < n;)
    {
      int j = i, curMin = a[i], curMax = a[i];
      while (j + 1 < n)
      {
        curMin = min(curMin, a[j + 1]);
        curMax = max(curMax, a[j + 1]);
        if (curMax - curMin <= d * 2) j++;
        else break;
      }
      ans++;
      i = j + 1;
    }

    cout << ans - 1 << '\n';
  }
}