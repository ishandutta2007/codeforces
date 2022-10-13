#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int oo = 27081993;

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
    string a, b;
    cin >> a >> b;

    vector<int> l(m + 1), r(m + 1); // num char to match prefix and suffix
    for (int i = 0, cur = 0; i < m; i++)
    {
      while (cur < n && a[cur] != b[i])
        cur++;
      l[i + 1] = cur + 1;
      if (cur < n)
        cur++;
    }
    for (int i = 1, cur = n - 1; i <= m; i++)
    {
      while (cur >= 0 && a[cur] != b[m - i])
        cur--;
      r[i] = n - cur;
      if (cur >= 0)
        cur--;
    }

    if (l[m] > n)
    {
      cout << -1 << '\n';
      continue;
    }

    int ans = n;
    for (int d = -n + 1; d < m; d++)
      for (int i = 0, cur = 0; i < n; i++)
      {
        int j = i + d;
        if (j >= 0 && j < m && a[i] == b[j])
        {
          cur++;
          int prefixA = i + 1 - cur, suffixA = n - 1 - i;
          int prefixB = j + 1 - cur, suffixB = m - 1 - j;
          if (l[prefixB] <= prefixA && r[suffixB] <= suffixA)
          {
            int cost = suffixA;
            if (prefixA)
              cost += 1 + prefixA * 2 - prefixB;
            ans = min(ans, cost);
          }
        }
        else cur = 0;
      }

    cout << ans << '\n';
  }
}