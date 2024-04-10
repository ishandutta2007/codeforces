#include <bits/stdc++.h>
using namespace std;

int n, flag[200200], onCycle[200200];
vector<int> a[200200], path, cycle;

int visit(int x, int par)
{
  flag[x] = path.size();
  path.push_back(x);
  for (int y : a[x])
    if (y != par)
    {
      if (flag[y] < 0)
      {
        if (visit(y, x))
          return 1;
      }
      else
      {
        for (int i = flag[y]; i < path.size(); i++)
        {
          onCycle[path[i]] = 1;
          cycle.push_back(path[i]);
        }
        return 1;
      }
    }

  path.pop_back();
  return 0;
}

int dfs(int x, int par)
{
  int res = 1;
  for (int y : a[x])
    if (y != par && !onCycle[y])
      res += dfs(y, x);
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      flag[i] = -1;
      onCycle[i] = 0;
      a[i].clear();
    }

    for (int i = 1; i <= n; i++)
    {
      int x, y;
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }

    path.clear();
    cycle.clear();
    visit(1, 0);

    long long ans = 0;
    for (int x : cycle)
    {
      int cnt = dfs(x, 0);
      ans += cnt * (cnt - 1LL) / 2;
      ans += 1LL * cnt * (n - cnt);
    }

    cout << ans << endl;
  }
}