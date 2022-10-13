#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<vector<int>> col(n);
  for (int i = 0; i < k; i++)
  {
    int c;
    cin >> c;
    while (c--)
    {
      int x;
      cin >> x;
      col[--x].push_back(i);
    }
  }

  vector<int> ds(k), pos(k, 1), neg(k), flip(k);
  int ans = 0;
  for (int i = 0; i < k; i++)
    ds[i] = i;

  function<pair<int, int>(int)> get = [&](int x)
  {
    if (x == ds[x])
      return pair<int, int>(x, 0);
    auto u = get(ds[x]);
    ds[x] = u.first;
    flip[x] ^= u.second;
    return pair<int, int>(ds[x], flip[x]);
  };

  auto join = [&](int u, int v, int shouldFlip)
  {
    auto [du, flipU] = get(u);
    auto [dv, flipV] = get(v);
    if (du == dv)
      return;
    ds[dv] = du;
    ans -= min(pos[du], neg[du]);
    ans -= min(pos[dv], neg[dv]);
    if (shouldFlip ^ flipU ^ flipV)
    {
      pos[du] = min(oo, pos[du] + neg[dv]);
      neg[du] = min(oo, neg[du] + pos[dv]);
      flip[dv] ^= 1;
    }
    else
    {
      pos[du] = min(oo, pos[du] + pos[dv]);
      neg[du] = min(oo, neg[du] + neg[dv]);
    }
    ans += min(pos[du], neg[du]);
  };

  for (int i = 0; i < n; i++)
  {
    if (size(col[i]) == 1)
    {
      int x = col[i][0];
      auto [dx, flipX] = get(x);
      ans -= min(pos[dx], neg[dx]);
      if ((s[i] == '0') ^ flipX) neg[dx] = oo;
      else pos[dx] = oo;
      ans += min(pos[dx], neg[dx]);
    }
    else if (size(col[i]) == 2)
    {
      int x = col[i][0], y = col[i][1];
      if (s[i] == '0') join(x, y, 1);
      else join(x, y, 0);
    }
    cout << ans << '\n';
  }
}