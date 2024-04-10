#include <bits/stdc++.h>
using namespace std;

struct DisjointSet
{
  int n;
  vector<int> ds, sz;

  DisjointSet(int n): n(n)
  {
    ds = sz = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
      ds[i] = i;
      sz[i] = 1;
    }
  }

  int get(int x)
  {
    return x == ds[x] ? x : ds[x] = get(ds[x]);
  }

  int join(int x, int y)
  {
    int dx = get(x), dy = get(y);
    if (dx == dy)
      return 0;
    if (sz[dx] < sz[dy])
      swap(dx, dy);
    ds[dy] = dx;
    sz[dx] += sz[dy];
    return 1;
  }
};

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
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> a[i][j];

    DisjointSet ds(n);
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (a[i][j] != a[j][i] && ds.join(i, j))
        {
          int w = a[i][j] > a[j][i];
          adj[i].push_back({j, w});
          adj[j].push_back({i, w});
        }

    vector<int> v(n, -1);
    function<void(int)> dfs = [&](int x)
    {
      for (auto [y, w] : adj[x])
        if (v[y] < 0)
        {
          v[y] = v[x] ^ w;
          dfs(y);
        }
    };

    for (int i = 0; i < n; i++)
      if (v[i] < 0)
      {
        v[i] = 0;
        dfs(i);
      }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cout << (v[i] ^ v[j] ? a[j][i] : a[i][j]) << " \n"[j == n - 1];
  }
}