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

    vector<int> ans(n + 1);
    set<int> s;
    for (int i = 1; i <= n; i++)
      s.insert(i);

    for (int i = 1; i < n; i++)
      if (a[i - 1] > a[i])
      {
        auto u = s.lower_bound(a[i - 1] - a[i]);
        assert(u != end(s));
        ans[*u] = i;
        s.erase(u);
      }

    for (int i = 1; i <= n; i++)
      cout << ans[i] + 1 << " \n"[i == n];
  }
}