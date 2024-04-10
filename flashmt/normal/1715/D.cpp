#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> bits(n, vector<int>(30, -1));
  vector<pair<int, int>> queries[30];
  while (q--)
  {
    int i, j, x;
    cin >> i >> j >> x;
    i--; j--;
    if (i > j)
      swap(i, j);
    for (int k = 0; k < 30; k++)
      if (i == j) bits[i][k] = x >> k & 1;
      else if (x >> k & 1) queries[k].push_back({i, j});
      else bits[i][k] = bits[j][k] = 0;
  }

  vector<int> ans(n);
  for (int i = 0; i < 30; i++)
  {
    sort(begin(queries[i]), end(queries[i]));
    for (auto [x, y] : queries[i])
      if (!bits[x][i]) bits[y][i] = 1;
      else if (!bits[y][i]) bits[x][i] = 1;

    for (auto [x, y] : queries[i])
      if (bits[x][i] != 1)
        bits[y][i] = 1;
  }

  for (int i = 0; i < n; i++)
  {
    int x = 0;
    for (int j = 0; j < 30; j++)
      if (bits[i][j] == 1)
        x |= 1 << j;
    cout << x << ' ';
  }
}