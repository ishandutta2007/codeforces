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
    vector<vector<int>> d(2, vector<int>(n));
    for (int i : {0, 1})
    {
      for (int &x : d[i])
        cin >> x;
      sort(begin(d[i]), end(d[i]));
    }

    vector<int> ans;
    int x0 = -1, x1 = -1;
    auto check = [&](int dist, int &x0, int &x1, vector<int> &ans)
    {
      if (x0 >= 0)
        return;
      multiset<int> s[2];
      for (int i : {0, 1})
        for (int x : d[i])
          s[i].insert(x);

      vector<int> l, r;
      while (!empty(s[0]))
      {
        auto u = rbegin(s[0]), v = rbegin(s[1]);
        if (*u > *v)
        {
          if (*u <= dist)
            break;
          auto w = s[1].find(*u - dist);
          if (w == end(s[1]))
            return;
          r.push_back(*u);
          s[1].erase(w);
          s[0].erase(s[0].find(*u));
        }
        else
        {
          if (*v <= dist)
            break;
          auto w = s[0].find(*v - dist);
          if (w == end(s[0]))
            return;
          l.push_back(*v);
          s[0].erase(w);
          s[1].erase(s[1].find(*v));
        }
      }

      auto u = begin(s[0]);
      auto v = rbegin(s[1]);
      while (u != end(s[0]))
      {
        if (*u + *v != dist)
          return;
        u++;
        v++;
      }

      x1 = max(d[1][n - 1], dist);
      x0 = x1 - dist;
      ans.clear();
      for (int x : r)
        ans.push_back(x0 + x);
      for (int x : l)
        ans.push_back(x1 - x);
      for (auto x : s[0])
        ans.push_back(x0 + x);
    };

    check(d[0][0] + d[1][n - 1], x0, x1, ans);
    for (int x : d[0])
      check(abs(x - d[1][n - 1]), x0, x1, ans);

    if (x0 < 0) cout << "NO\n";
    else
    {
      cout << "YES\n";
      for (int x : ans)
        cout << x << ' ';
      cout << '\n';
      cout << x0 << ' ' << x1 << '\n';
    }
  }
}