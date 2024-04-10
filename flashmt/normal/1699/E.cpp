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
    int n, m;
    cin >> n >> m;
    vector<int> flag(m + 1);
    int minA = m, maxA = 1;
    while (n--)
    {
      int x;
      cin >> x;
      flag[x] = 1;
      minA = min(minA, x);
      maxA = max(maxA, x);
    }

    vector<int> f(m + 1, m + 1), cnt(m + 1);
    int ans = maxA - minA;
    for (int i = maxA, curMax = maxA; i; i--)
    {
      for (int j = i; j <= maxA; j += i)
      {
        if (f[j] <= m && flag[j])
          cnt[f[j]]--;
        f[j] = min(f[j], j);
        if (j / i >= i)
          f[j] = min(f[j], f[j / i]);
        if (flag[j])
          cnt[f[j]]++;
      }

      while (!cnt[curMax])
        curMax--;

      if (i <= minA)
        ans = min(ans, curMax - i);
    }

    cout << ans << '\n';
  }
}