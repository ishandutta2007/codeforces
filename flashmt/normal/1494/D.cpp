#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int A = 5555;

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
    ds[dy] = dx;
    sz[dx] += sz[dy];
    return 1;
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  vector<int> c(n * 2), par(n * 2, -1);
  DisjointSet ds(n * 2);
  for (int i = 0; i < n; i++)
    c[i] = a[i][i];

  vector<vector<pair<int, int>>> at(A);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      at[a[i][j]].push_back({i, j});

  for (int curC = 1; curC < A; curC++)
  {
    if (empty(at[curC]))
      continue;

    for (auto &[x, y] : at[curC])
    {
      x = ds.get(x);
      y = ds.get(y);
      if (x > y)
        swap(x, y);
    }
    sort(begin(at[curC]), end(at[curC]));

    for (int i = 0; i < size(at[curC]);)
    {
      int x = at[curC][i].first;
      if (par[x] >= 0)
      {
        i++;
        continue;
      }

      set<int> nodes = {x};
      int j = i;
      while (j < size(at[curC]))
      {
        auto [xx, y] = at[curC][j];
        if (xx != x)
          break;
        nodes.insert(y);
        j++;
      }

      for (int x : nodes)
      {
        par[x] = n;
        ds.join(n, x);
      }
      c[n++] = curC;

      i = j;
    }
  }

  cout << n << endl;
  for (int i = 0; i < n; i++)
    cout << c[i] << " \n"[i == n - 1];
  cout << n << endl;
  for (int i = 0; i < n; i++)
    if (par[i] >= 0)
      cout << i + 1 << ' ' << par[i] + 1 << endl;
}