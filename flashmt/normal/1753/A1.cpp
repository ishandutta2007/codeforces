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
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (i % 2)
        a[i] = -a[i];
    }

    if (n % 2) cout << -1 << endl;
    else
    {
      vector<pair<int, int>> ans;
      for (int i = 0; i < n; i += 2)
        if (a[i] == a[i + 1])
        {
          ans.push_back({i, i});
          ans.push_back({i + 1, i + 1});
        }
        else ans.push_back({i, i + 1});
      cout << size(ans) << '\n';
      for (auto [l, r] : ans)
        cout << l + 1 << ' ' << r + 1 << '\n';
    }
  }
}