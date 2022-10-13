#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, s;
  cin >> n >> m >> s;
  s--;
  vector<vector<int>> a(n);
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (y != s)
      a[x].push_back(y);
  }

  vector<int> flag(n, -1), tr(n);

  auto trace = [&](int x)
  {
    vector<int> res;
    for (; x != s; x = tr[x])
      res.push_back(x);
    res.push_back(s);
    reverse(begin(res), end(res));
    return res;
  };

  auto printAns = [&](int x, int y)
  {
    cout << "Possible\n";
    vector<vector<int>> paths = {trace(x), trace(y)};
    paths[0].push_back(y);
    for (auto path : paths)
    {
      cout << size(path) << '\n';
      for (int u : path)
        cout << u + 1 << ' ';
      cout << '\n';
    }
    exit(0);
  };

  function<void(int, int)> dfs = [&](int x, int curBranch)
  {
    flag[x] = curBranch;
    for (int y : a[x])
      if (flag[y] < 0)
      {
        tr[y] = x;
        dfs(y, curBranch);
      }
      else if (flag[y] != curBranch)
      {
        printAns(x, y);
      }
  };

  for (int x : a[s])
    if (flag[x] >= 0) printAns(s, x);
    else
    {
      tr[x] = s;
      dfs(x, x);
    }

  cout << "Impossible\n";
}