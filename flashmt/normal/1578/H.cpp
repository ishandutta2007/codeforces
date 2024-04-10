#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  vector<pair<int, int>> edges;
  function<void(int, int)> dfs = [&](int x, int par)
  {
    for (int y : a[x])
      if (y != par)
      {
        edges.push_back({x, y});
        dfs(y, x);
      }
  };

  auto query = [&](set<int> &s)
  {
    cout << "? " << size(s);
    for (int x : s)
      cout << ' ' << x + 1;
    cout << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
  };

  set<int> all;
  for (int i = 0; i < n; i++)
    all.insert(i);
  int maxGcd = query(all);

  dfs(0, -1);

  int low = 0, high = n - 2, ans = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    set<int> s;
    for (int i = 0; i <= mid; i++)
    {
      s.insert(edges[i].first);
      s.insert(edges[i].second);
    }
    if (query(s) == maxGcd)
    {
      ans = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }

  cout << "! " << edges[ans].first + 1 << ' ' << edges[ans].second + 1 << endl;
  cout.flush();
}