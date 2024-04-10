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
  int test;
  cin >> test;
  while (test--)
  {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    vector<vector<int>> d(n, vector<int>(n, n));
    for (int i = 0; i < n; i++)
      d[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
      int x, y, w;
      cin >> x >> y >> w;
      x--; y--;
      edges.push_back({x, y, w});
      d[x][y] = d[y][x] = 1;
    }

    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    long long ans = 1LL << 60;
    for (int i = 0; i < m; i++)
    {
      auto [x, y, w] = edges[i];
      int minEdge = 1 << 30;
      minEdge = min(minEdge, d[0][x] + d[n - 1][y]);
      minEdge = min(minEdge, d[0][y] + d[n - 1][x]);
      for (int j = 0; j < n; j++)
        minEdge = min(minEdge, min(d[x][j], d[y][j]) + 1 + d[0][j] + d[j][n - 1]);
      ans = min(ans, (minEdge + 1LL) * w);
    }
    cout << ans << endl;
  }
}