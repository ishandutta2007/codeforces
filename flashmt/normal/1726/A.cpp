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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    int ans = a[n - 1] - a[0];
    if (n > 1)
    {
      ans = max(ans, a[n - 1] - *min_element(begin(a), begin(a) + n - 1));
      ans = max(ans, *max_element(begin(a) + 1, end(a)) - a[0]);
      for (int i = 1; i < n; i++)
        ans = max(ans, a[i - 1] - a[i]);
    }
    cout << ans << endl;
  }
}