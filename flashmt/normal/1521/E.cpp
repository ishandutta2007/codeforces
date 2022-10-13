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
    int m, k;
    cin >> m >> k;
    vector<pair<int, int>> a;
    for (int i = 1; i <= k; i++)
    {
      int x;
      cin >> x;
      if (x)
        a.push_back({x, i});
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());

    for (int n = 1; n <= 633; n++)
    {
      if ((n + 1) / 2 * n < a[0].first || n * n - (n / 2) * (n / 2) < m)
        continue;

      vector<vector<int>> ans(n, vector<int>(n));
      queue<pair<int, int>> q;

      for (int i = 0; i < n; i += 2)
        for (int j = 1; j < n; j += 2)
          q.push({i, j});

      for (int i = 0; i < n; i += 2)
        for (int j = 0; j < n; j += 2)
          q.push({i, j});

      for (int i = 1; i < n; i += 2)
        for (int j = 0; j < n; j += 2)
          q.push({i, j});

      for (auto [cnt, value] : a)
        while (cnt--)
        {
          auto [x, y] = q.front();
          q.pop();
          ans[x][y] = value;
        }

      cout << n << '\n';
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          cout << ans[i][j] << " \n"[j == n - 1];

      break;
    }
  }
}