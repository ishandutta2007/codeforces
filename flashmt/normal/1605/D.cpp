#include <bits/stdc++.h>
using namespace std;
const int LG = 17;

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

    vector<int> nodes[2];
    auto dfs = [&](auto self, int x, int par, int c) -> void
    {
      nodes[c].push_back(x);
      for (int y : a[x])
        if (y != par)
          self(self, y, x, c ^ 1);
    };

    dfs(dfs, 0, -1, 0);
    int cnt = size(nodes[1]);
    vector<vector<int>> b(LG + 1);
    for (int i = 1; i <= n; i++)
      b[__lg(i)].push_back(i);

    vector<int> ans(n);
    for (int i = LG; i >= 0; i--)
    {
      int c = 0;
      if (cnt >= size(b[i]))
      {
        cnt -= size(b[i]);
        c = 1;
      }

      for (int j : b[i])
      {
        ans[nodes[c].back()] = j;
        nodes[c].pop_back();
      }
    }

    for (int x : ans)
      cout << x << ' ';
    cout << '\n';
  }
}