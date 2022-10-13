#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int n, depth[222];
long long f[222][222], ans;
vector<int> a[222], child[222];

long long power(long long x, long long y)
{
  if (!y)
    return 1;
  long long res = power(x, y >> 1);
  res = res * res % BASE;
  if (y & 1)
    res = res * x % BASE;
  return res;
}

void visit(int x, int par)
{
  child[x].clear();
  for (int y : a[x])
    if (y != par)
    {
      depth[y] = depth[x] + 1;
      visit(y, x);
      for (int u : child[y])
      {
        if (u < x)
          ans = (ans + 1) % BASE;
        int du = depth[u] - depth[x];
        for (int v : child[x])
        {
          int dv = depth[v] - depth[x];
          if (u > v) ans = (ans + f[du][dv]) % BASE;
          else ans = (ans + f[dv][du]) % BASE;
        }
      }

      for (int u : child[y])
        child[x].push_back(u);
    }

  child[x].push_back(x);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i <= 200; i++)
    f[0][i] = 1;
  for (int i = 1; i <= 200; i++)
    for (int j = 1; j <= 200; j++)
      f[i][j] = (f[i - 1][j] + f[i][j - 1]) * power(2, BASE - 2) % BASE;

  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  ans = 0;
  for (int i = 1; i <= n; i++)
  {
    depth[i] = 0;
    visit(i, 0);
  }

  ans = ans * power(n, BASE - 2) % BASE;
  cout << ans << endl;
}