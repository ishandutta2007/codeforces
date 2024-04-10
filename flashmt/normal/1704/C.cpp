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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int &x : a)
    {
      cin >> x;
      x--;
    }
    sort(begin(a), end(a));

    set<pair<int, int>> s;
    for (int i = 0; i < m; i++)
    {
      int diff = (a[(i + 1) % m] - a[i] - 1 + n) % n;
      s.insert({diff, i});
    }

    int ans = 0;
    for (int days = 0; !empty(s);)
    {
      auto [diff, _] = *rbegin(s);
      s.erase(*rbegin(s));
      diff -= days * 2;
      if (diff <= 0)
        break;

      if (diff <= 2)
      {
        ans++;
        days++;
      }
      else
      {
        ans += diff - 1;
        days += 2;
      }
    }

    cout << n - ans << '\n';
  }
}