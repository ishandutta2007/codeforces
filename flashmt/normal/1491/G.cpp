#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
  }

  vector<vector<int>> cycles;
  vector<int> seen(n), good;
  for (int i = 0; i < n; i++)
    if (!seen[i])
    {
      int x = i;
      vector<int> cycle;
      while (!seen[x])
      {
        cycle.push_back(x);
        seen[x] = 1;
        x = a[x];
      }
      if (size(cycle) == 1) good.push_back(i);
      else cycles.push_back(cycle);
    }

  vector<pair<int, int>> ans;
  for (int i = 0; i + 1 < size(cycles); i += 2)
  {
    auto l = cycles[i], r = cycles[i + 1];
    ans.push_back({l[0], r[0]});
    for (int j = 1; j < size(l); j++)
      ans.push_back({l[j], r[0]});
    for (int j = 1; j < size(r); j++)
      ans.push_back({l[0], r[j]});
    ans.push_back({l[0], r[0]});
  }

  if (size(cycles) % 2)
  {
    auto c = cycles.back();
    int sz = size(c);
    if (sz == 2)
    {
      for (int i = 0; i < n; i++)
        if (i != c[0] && i != c[1])
        {
          ans.push_back({c[1], i});
          ans.push_back({c[0], i});
          ans.push_back({c[1], i});
          break;
        }
    }
    else
    {
      ans.push_back({c[0], c[1]});
      for (int i = 2; i < sz - 1; i++)
        ans.push_back({c[0], c[i]});
      ans.push_back({c[1], c[sz - 1]});
      ans.push_back({c[0], c[sz - 1]});
      ans.push_back({c[0], c[1]});
    }
  }

  assert(size(ans) <= n + 1);
  cout << size(ans) << '\n';
  for (auto [x, y] : ans)
    cout << x + 1 << ' ' << y + 1 << '\n';
}