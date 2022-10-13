#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> x(n * n), y(n * n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      int v;
      cin >> v;
      v--;
      x[v] = i + j;
      y[v] = i - j;
    }

  vector<string> ans(n, string(n, 'G'));
  int minX = 0, maxX = n * 2 - 2;
  int minY = -n + 1, maxY = n - 1;
  for (int v = n * n - 1; v >= 0; v--)
    if (minX <= x[v] && x[v] <= maxX && minY <= y[v] && y[v] <= maxY)
    {
      ans[(x[v] + y[v]) / 2][(x[v] - y[v]) / 2] = 'M';
      minX = max(minX, x[v] - k);
      maxX = min(maxX, x[v] + k);
      minY = max(minY, y[v] - k);
      maxY = min(maxY, y[v] + k);
    }

  for (auto s : ans)
    cout << s << '\n';
}