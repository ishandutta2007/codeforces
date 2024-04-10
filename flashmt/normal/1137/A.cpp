#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, n, a[1010][1010];
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  int rankRow[1010][1010], maxRow[1010];
  for (int i = 0; i < m; i++)
  {
    vector<pair<int, int>> b;
    for (int j = 0; j < n; j++)
      b.push_back({a[i][j], j});
    sort(b.begin(), b.end());

    int rank = -1, curA = 0;
    for (auto u : b)
    {
      if (u.first > curA)
      {
        curA = u.first;
        rank++;
      }
      rankRow[i][u.second] = rank;
    }
    maxRow[i] = rank;
  }

  int rankCol[1010][1010], maxCol[1010];
  for (int j = 0; j < n; j++)
  {
    vector<pair<int, int>> b;
    for (int i = 0; i < m; i++)
      b.push_back({a[i][j], i});
    sort(b.begin(), b.end());

    int rank = -1, curA = 0;
    for (auto u : b)
    {
      if (u.first > curA)
      {
        curA = u.first;
        rank++;
      }
      rankCol[u.second][j] = rank;
    }
    maxCol[j] = rank;
  }

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      int ans = max(rankRow[i][j], rankCol[i][j]) + max(maxRow[i] - rankRow[i][j], maxCol[j] - rankCol[i][j]);
      cout << ans + 1 << " \n"[j == n - 1];
    }
}