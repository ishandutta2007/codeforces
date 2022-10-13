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
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < n; j++)
        cin >> a[i][j];

    vector<int> maxR01(n), maxR10(n);
    for (int i = n - 1; i >= 0; i--)
    {
      if (!i) maxR01[i] = max(0, a[1][0] - (2 * n - 2));
      else
      {
        maxR01[i] = max(a[0][i] - (i - 1), a[1][i] - (2 * n - 2 - i));
        maxR10[i] = max(a[0][i] - (2 * n - 2 - i), a[1][i] - (i - 1));
      }
      if (i + 1 < n)
      {
        maxR01[i] = max(maxR01[i], maxR01[i + 1]);
        maxR10[i] = max(maxR10[i], maxR10[i + 1]);
      }
    }

    int ans = maxR01[0] + n * 2 - 1;
    for (int i = 0, t = 0; i < n; i++)
    {
      if (!i) t = a[1][0] + 1;
      else
      {
        t = max(t, a[i % 2][i]) + 1;
        t = max(t, a[1 - i % 2][i]) + 1;
      }

      if (i == n - 1) ans = min(ans, t);
      else if (i % 2) ans = min(ans, t + (n - 1 - i) * 2 + max(0, maxR01[i + 1] + i - t));
      else ans = min(ans, t + (n - 1 - i) * 2 + max(0, maxR10[i + 1] + i - t));
    }
    cout << ans << '\n';
  }
}