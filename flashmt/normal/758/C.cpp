#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n, m, k, x, y;
  cin >> n >> m >> k >> x >> y;
  long long minAsked = k, maxAsked = 0, sergeiAsked;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      long long numRow = n > 2 ? 2 * n - 2 : n;
      long long cycle = k / (numRow * m);
      long long remaining = k % (numRow * m);
      long long lastRow = (remaining - 1) / m;
      long long lastCol = (remaining - 1) % m;
      long long asked = i && i < n - 1 ? cycle * 2 : cycle;
      if (remaining <= n * m) 
      {
        asked += (i < lastRow) || (i == lastRow && j <= lastCol);
      }
      else 
      {
        asked++;
        if (i && i < n - 1)
        {
          lastRow = (n - 1) * 2 - lastRow;
          asked += (i > lastRow) || (i == lastRow && j <= lastCol);
        }
      }

      minAsked = min(minAsked, asked);
      maxAsked = max(maxAsked, asked);
      if (i == x - 1 && j == y - 1) 
        sergeiAsked = asked;
    }
  cout << maxAsked << ' ' << minAsked << ' ' << sergeiAsked << endl;
}