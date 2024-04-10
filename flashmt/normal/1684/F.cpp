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
    vector<int> a(n), l(n, -1), r(n, n);
    map<int, int> seen;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (seen.count(a[i]))
      {
        l[i] = seen[a[i]];
        r[l[i]] = i;
      }
      seen[a[i]] = i;
    }

    vector<int> bound(n);
    map<int, int> cnt;
    for (int i = n - 1, j = n; i >= 0; i--)
    {
      while (j && !cnt[a[j - 1]])
        cnt[a[--j]]++;
      bound[i] = j;
      cnt[a[i]]--;
    }

    int curR = -1;
    vector<int> maxR(n, -1);
    while (m--)
    {
      int x, y;
      cin >> x >> y;
      x--; y--;
      if (bound[y] <= x) // distinct segment already
        continue;

      curR = max(curR, bound[y] - 1);
      maxR[x] = max(maxR[x], y);
    }

    if (curR < 0)
    {
      cout << 0 << '\n';
      continue;
    }

    for (int i = 1; i < n; i++)
      maxR[i] = max(maxR[i], maxR[i - 1]);

    vector<int> bad(n, -1); // max j such that a[j] = a[i] and there exists a segment covering (i, j)
    for (int i = 0; i < n; i++)
    {
      bad[i] = l[i] >= 0 ? bad[l[i]] : i;
      while (r[bad[i]] <= maxR[i])
        bad[i] = r[bad[i]];
    }

    int ans = curR + 1;
    for (int i = 1; i < n; i++)
      if (l[i - 1] >= 0 && maxR[l[i - 1]] >= i - 1) break;
      else
      {
        if (r[i - 1] <= maxR[i - 1])
          curR = max(curR, bad[i - 1]);
        ans = min(ans, curR - i + 1);
      }

    cout << ans << '\n';
  }
}