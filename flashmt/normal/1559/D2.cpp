#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m[2];
  cin >> n >> m[0] >> m[1];
  vector<vector<int>> ds(2, vector<int>(n));
  for (int i = 0; i < n; i++)
    ds[0][i] = ds[1][i] = i;

  function<int(vector<int>&, int)> get = [&](vector<int> &ds, int x)
  {
    return x == ds[x] ? x : ds[x] = get(ds, ds[x]);
  };

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < m[i]; j++)
    {
      int x, y;
      cin >> x >> y;
      ds[i][get(ds[i], --y)] = get(ds[i], --x);
    }

  auto join = [&](int x, int y)
  {
    for (int i = 0; i < 2; i++)
      if (get(ds[i], x) == get(ds[i], y))
        return 0;
    for (int i = 0; i < 2; i++)
      ds[i][get(ds[i], y)] = get(ds[i], x);
    return 1;
  };

  vector<pair<int, int>> ans;
  for (int i = 1; i < n; i++)
    if (join(0, i))
      ans.push_back({0, i});

  vector<int> nodes[2];
  for (int i = 1; i < n; i++)
    for (int j = 0; j < 2; j++)
      if (get(ds[j], i) != get(ds[j], 0))
        nodes[j].push_back(i);

  while (1)
  {
    int x[2] = {-1, -1};
    for (int i = 0; i < 2; i++)
      while (size(nodes[i]))
      {
        int y = nodes[i].back();
        nodes[i].pop_back();
        if (get(ds[i], y) != get(ds[i], 0))
        {
          x[i] = y;
          break;
        }
      }

    if (x[0] < 0 ||  x[1] < 0)
      break;

    ans.push_back({x[0], x[1]});
    join(x[0], x[1]);
  }

  cout << size(ans) << '\n';
  for (auto [x, y] : ans)
    cout << x + 1 << ' ' << y + 1 << '\n';
}