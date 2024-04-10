#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = 1 << 30;

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
    vector<pair<int, int>> segs[2];
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
      int c, l, r;
      cin >> c >> l >> r;
      segs[c].push_back({l, ++r});
      m[l] = m[r] = 0;
    }
    segs[0].push_back({oo - 1, oo});
    m[oo - 1] = m[oo] = 0;

    int cnt = 0;
    for (auto [k, _] : m)
      m[k] = cnt++;
    for (int c : {0, 1})
    {
      for (auto &u : segs[c])
        u = {m[u.first], m[u.second]};
      sort(begin(segs[c]), end(segs[c]));
    }

    set<int> alive, seen;
    for (int i = 0; i <= cnt; i++)
      alive.insert(i);
    seen = {cnt};

    int ans = 0;
    for (int i = 0, j = 0; i < size(segs[0]); i++)
    {
      auto [l, r] = segs[0][i];
      if (*seen.lower_bound(l) >= r)
        ans++;
      while (j < size(segs[1]))
      {
        auto [ll, rr] = segs[1][j];
        if (rr <= l)
        {
          ans++;
          j++;
        }
        else if (ll < r)
        {
          auto u = alive.lower_bound(ll);
          while (*u < rr)
          {
            seen.insert(*u);
            u = alive.erase(u);
          }
          j++;
        }
        else break;
      }
    }

    cout << ans - 1 << endl;
  }
}