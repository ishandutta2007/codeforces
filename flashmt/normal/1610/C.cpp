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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
      cin >> a[i] >> b[i];

    int low = 1, high = n, ans = 0;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      int cur = 0;
      for (int i = 0; i < n && cur < mid; i++)
        if (a[i] >= mid - 1 - cur && b[i] >= cur)
          cur++;

      if (cur == mid)
      {
        ans = mid;
        low = mid + 1;
      }
      else high = mid - 1;
    }

    cout << ans << endl;
  }
}