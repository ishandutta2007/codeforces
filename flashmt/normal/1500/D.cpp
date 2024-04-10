// G++20 speed test, what if no long long is involved?

#include <bits/stdc++.h>
using namespace std;
const int N = 1515;

int n, maxColor, a[N][N], f[N][N];
vector<pair<int, int>> cells[N][N];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> maxColor;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
      a[i][j]--;
    }

  vector<int> ans(n + 1), seen(n * n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      vector<pair<int, int>> curCells = {{1, a[i][j]}};
      f[i][j] = min(i + 1, j + 1);

      auto update = [&](int ii, int jj)
      {
        f[i][j] = min(f[i][j], f[ii][jj] + 1);
        for (auto [dist, color] : cells[ii][jj])
          curCells.push_back({dist + 1, color});
      };

      if (i)
        update(i - 1, j);
      if (j)
        update(i, j - 1);
      if (i && j)
        update(i - 1, j - 1);

      sort(begin(curCells), end(curCells));
      int cellSize = 0;
      for (auto [dist, color] : curCells)
        if (dist <= f[i][j] && !seen[color])
        {
          seen[color] = 1;
          curCells[cellSize++] = {dist, color};
        }
      for (auto [_, color] : curCells)
        seen[color] = 0;

      if (cellSize > maxColor)
      {
        f[i][j] = curCells[maxColor].first - 1;
        while (curCells[cellSize - 1].first > f[i][j])
          cellSize--;
      }
      cells[i][j].assign(begin(curCells), begin(curCells) + cellSize);

      ans[f[i][j]]++;
    }

  for (int i = n; i; i--)
    ans[i - 1] += ans[i];

  for (int i = 1; i <= n; i++)
    cout << ans[i] << '\n';
}