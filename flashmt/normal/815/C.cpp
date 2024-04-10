#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = (1 << 30) - 10;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, budget;
  cin >> n >> budget;
  vector<int> c(n), d(n), par(n);
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> c[i] >> d[i];
    if (i)
    {
      cin >> par[i];
      a[--par[i]].push_back(i);
    }
  }

  vector<vector<int>> f(n); // can use coupon
  vector<vector<int>> g(n); // can't use coupon
  vector<int> sz(n);
  function<void(int)> dfs = [&](int x)
  {
    f[x] = g[x] = {0};
    for (int y : a[x])
    {
      dfs(y);
      vector<int> newF(sz[x] + sz[y] + 1, oo);
      auto newG = newF;
      for (int i = 0; i <= sz[x]; i++)
        for (int j = 0; j <= sz[y]; j++)
        {
          newF[i + j] = min(newF[i + j], f[x][i] + min(f[y][j], g[y][j]));
          newG[i + j] = min(newG[i + j], g[x][i] + g[y][j]);
        }

      sz[x] += sz[y];
      swap(f[x], newF);
      swap(g[x], newG);
    }

    sz[x]++;

    f[x].push_back(oo);
    for (int i = sz[x]; i; i--)
      f[x][i] = min(f[x][i - 1] + c[x] - d[x], oo);

    g[x].push_back(min(g[x][sz[x] - 1] + c[x], oo));
    for (int i = sz[x] - 1; i; i--)
      g[x][i] = min(g[x][i], g[x][i - 1] + c[x]);
  };

  dfs(0);
  for (int i = n; i >= 0; i--)
    if (min(f[0][i], g[0][i]) <= budget)
    {
      cout << i << endl;
      break;
    }
}