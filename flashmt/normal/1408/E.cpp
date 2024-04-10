#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vector<int> setCosts(m), valueCosts(n);
  for (int &x : setCosts)
    cin >> x;
  for (int &x : valueCosts)
    cin >> x;
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++)
  {
    int sz;
    cin >> sz;
    while (sz--)
    {
      int j;
      cin >> j;
      j--;
      edges.push_back({setCosts[i] + valueCosts[j], i, j + m});
    }
  }

  vector<int> ds(m + n);
  for (int i = 0; i < m + n; i++)
    ds[i] = i;

  function<int(int)> get = [&](int x)
  {
    return x == ds[x] ? x : ds[x] = get(ds[x]);
  };

  long long ans = 0;
  sort(rbegin(edges), rend(edges));
  for (auto [cost, x, y] : edges)
    if (get(x) != get(y)) ds[get(y)] = get(x);
    else ans += cost;
  cout << ans << endl;
}