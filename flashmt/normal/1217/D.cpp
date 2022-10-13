#include <bits/stdc++.h>
using namespace std;

int n, m, ans[5050], hasCycle, flag[5050];
vector<pair<int, int>> a[5050];

void dfs(int x)
{
  flag[x] = 1;
  for (auto u : a[x])
  {
    int y = u.first, id = u.second;
    if (!flag[y]) dfs(y);
    else if (flag[y] > 0)
    {
      hasCycle = 1;
      ans[id] = 1;
    }
  }
  flag[x] = -1;
}

int main()
{
  int x, y;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> x >> y;
    a[x].push_back({y, i});
  }

  for (int i = 1; i <= n; i++)
    a[0].push_back({i, -1});

  dfs(0);

  cout << hasCycle + 1 << endl;
  for (int i = 0; i < m; i++)
    cout << ans[i] + 1 << ' ';
}