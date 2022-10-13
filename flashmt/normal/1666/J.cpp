#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const long long oo = 1LL << 60;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<long long>> c(n + 1, vector<long long>(n + 1));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      cin >> c[i][j];
      c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
    }

  auto getRect = [&](int x, int xx, int y, int yy)
  {
    return c[xx][yy] + c[x - 1][y - 1] - c[x - 1][yy] - c[xx][y - 1];
  };

  vector<vector<long long>> f(n + 2, vector<long long>(n + 2));
  vector<vector<int>> tr(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++)
    tr[i][i] = i;
  for (int len = 2; len <= n; len++)
    for (int i = 1; i + len - 1 <= n; i++)
    {
      int j = i + len - 1;
      f[i][j] = oo;
      for (int k = i; k <= j; k++)
      {
        long long cost = f[i][k - 1] + f[k + 1][j];
        cost += getRect(k, k, i, j);
        cost += getRect(i, k - 1, k + 1, j) * 2;
        cost += getRect(i, k - 1, 1, i - 1);
        cost += getRect(i, k - 1, j + 1, n);
        cost += getRect(k + 1, j, 1, i - 1);
        cost += getRect(k + 1, j, j + 1, n);
        if (cost < f[i][j])
        {
          f[i][j] = cost;
          tr[i][j] = k;
        }
      }
    }

  vector<int> par(n + 1);
  function<void(int, int)> trace = [&](int i, int j)
  {
    if (i == j)
      return;
    int k = tr[i][j];
    if (i < k)
    {
      par[tr[i][k - 1]] = k;
      trace(i, k - 1);
    }
    if (k < j)
    {
      par[tr[k + 1][j]] = k;
      trace(k + 1, j);
    }
  };

  trace(1, n);
  for (int i = 1; i <= n; i++)
    cout << par[i] << " \n"[i == n];
}