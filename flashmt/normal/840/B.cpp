#include <bits/stdc++.h>
using namespace std;
const int N = 300300;

vector<pair<int, int>> a[N];
int d[N], isGood[N];

void dfs(int x, int par = -1)
{
  int parEdgeId = -1, deg = 0;
  for (auto [y, id] : a[x])
    if (y == par) parEdgeId = id;
    else
    {
      dfs(y, x);
      deg ^= isGood[id];
    }

  if (d[x] < 0)
    return;

  if (deg != d[x] && parEdgeId < 0)
  {
    cout << -1 << endl;
    exit(0);
  }

  if (d[x] >= 0 && deg == d[x] && parEdgeId >= 0)
    isGood[parEdgeId] = 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int root = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> d[i];
    if (d[i] < 0)
      root = i;
  }

  vector<int> ds(n);
  iota(begin(ds), end(ds), 0);
  function<int(int)> get = [&](int x)
  {
    return x == ds[x] ? x : ds[x] = get(ds[x]);
  };

  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    int dx = get(--x), dy = get(--y);
    if (dx != dy)
    {
      a[x].push_back({y, i});
      a[y].push_back({x, i});
      ds[dy] = dx;
      isGood[i] = 1;
    }
  }

  dfs(root);
  cout << accumulate(isGood, isGood + m, 0) << endl;
  for (int i = 0; i < m; i++)
    if (isGood[i])
      cout << i + 1 << ' ';
}