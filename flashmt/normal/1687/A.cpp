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
    int n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
      int x;
      cin >> x;
      a[i] = a[i - 1] + x;
    }

    long long maxSeg = 0;
    int len = min(n, k);
    for (int i = len; i <= n; i++)
      maxSeg = max(maxSeg, a[i] - a[i - len]);

    long long ans = maxSeg;
    if (k <= n) ans += k * (k - 1LL) / 2;
    else ans += 1LL * k * n - n * (n + 1LL) / 2;
    cout << ans << endl;
  }
}