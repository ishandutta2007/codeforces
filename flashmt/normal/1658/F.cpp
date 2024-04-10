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
    string s;
    cin >> n >> m >> s;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++)
      a[i +  1] = a[i] + s[i] - '0';

    if (1LL * a[n] * m % n)
    {
      cout << -1 << '\n';
      continue;
    }

    int one = 1LL * a[n] * m / n;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
      int j = (i + m - 1) % n;
      int curOne = i <= j ? a[j + 1] - a[i] : a[j + 1] + (a[n] - a[i]);
      if (curOne == one)
      {
        vector<pair<int, int>> segs;
        if (i <= j) segs = {{i, j}};
        else segs = {{0, j}, {i, n - 1}};
        if (empty(ans) || size(segs) < size(ans))
          ans = segs;
      }
    }

    cout << size(ans) << '\n';
    for (auto [l, r] : ans)
      cout << l + 1 << ' ' << r + 1 << '\n';
  }
}