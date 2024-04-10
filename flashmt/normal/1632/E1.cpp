#include <bits/stdc++.h>
using namespace std;

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
    vector<int> d(n), maxD(n), maxPathAtDepth(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
      int x, y;
      cin >> x >> y;
      a[--x].push_back(--y);
      a[y].push_back(x);
    }

    auto dfs = [&](auto self, int x, int par) -> void
    {
      int secondMaxD = d[x];
      maxD[x] = d[x];
      for (int y : a[x])
        if (y != par)
        {
          d[y] = d[x] + 1;
          self(self, y, x);
          if (maxD[y] > maxD[x])
          {
            secondMaxD = maxD[x];
            maxD[x] = maxD[y];
          }
          else secondMaxD = max(secondMaxD, maxD[y]);
        }

      if (secondMaxD)
        maxPathAtDepth[secondMaxD - 1] = max(maxPathAtDepth[secondMaxD - 1], maxD[x] + secondMaxD - d[x] * 2);
    };

    dfs(dfs, 0, -1);
    for (int i = n - 2; i >= 0; i--)
      maxPathAtDepth[i] = max(maxPathAtDepth[i], maxPathAtDepth[i + 1]);

    for (int i = 1, ans = 1; i <= n; i++)
    {
      while (ans < maxD[0] && (maxPathAtDepth[ans] + 1) / 2 + i > ans)
        ans++;
      cout << ans << " \n"[i == n];
    }
  }
}