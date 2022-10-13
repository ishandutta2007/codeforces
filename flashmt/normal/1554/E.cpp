#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

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
    vector<vector<int>> a(n);
    for (int i = 1; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      a[--x].push_back(--y);
      a[y].push_back(x);
    }

    vector<long long> f(n + 1);
    f[1] = 1;
    for (int i = 0; i < n - 1; i++)
      f[1] = f[1] * 2 % BASE;

    vector<int> v(n);
    auto dfs = [&](auto self, int x, int par, int k) -> void
    {
      v[x] = 0;
      for (int y : a[x])
        if (y != par)
          self(self, y, x, k);

      if (x == 0)
        return;

      if (v[x]) v[x] = (v[x] + 1) % k;
      else v[par] = (v[par] + 1) % k;
    };

    for (int i = 2; i < n; i++)
      if ((n - 1) % i == 0)
      {
        dfs(dfs, 0, -1, i);
        if (all_of(begin(v), end(v), [](int x) { return x == 0; }))
          f[i] = 1;
      }

    for (int i = n; i; i--)
      for (int j = i * 2; j <= n; j += i)
        f[i] = (f[i] - f[j] + BASE) % BASE;

    for (int i = 1; i <= n; i++)
      cout << f[i] << " \n"[i == n];
  }
}