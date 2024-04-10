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
  int n, k;
  cin >> n >> k;

  vector<int> flag(n * n);
  vector<int> minCol(n * n, n), maxCol(n * n);
  vector<int> minRow(n * n, n), maxRow(n * n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      int x;
      cin >> x;
      flag[--x] = 1;
      minCol[x] = min(minCol[x], j);
      maxCol[x] = max(maxCol[x], j);
      minRow[x] = min(minRow[x], i);
      maxRow[x] = i;
    }

  int initial = accumulate(begin(flag), end(flag), 0);
  if (initial <= k) cout << k - initial << endl;
  else if (k == 1) cout << 1 << endl;
  else
  {
    // we can always achieve with 2 ops, try to check 1 op is possible
    int diff = initial - k;
    vector<vector<int>> f(n + 1, vector<int>(n + 1));
    for (int len = 1; len < n; len++)
    {
      for (int i = 0; i + len <= n; i++)
        for (int j = 0; j + len <= n; j++)
          f[i][j] = 0;

      for (int x = 0; x < n * n; x++)
        if (minRow[x] <= maxRow[x] && maxRow[x] - minRow[x] + 1 <= len && maxCol[x] - minCol[x] + 1 <= len)
        {
          int i = max(0, maxRow[x] - len + 1), ii = minRow[x] + 1;
          int j = max(0, maxCol[x] - len + 1), jj = minCol[x] + 1;
          f[i][j]++;
          f[i][jj]--;
          f[ii][j]--;
          f[ii][jj]++;
        }

      for (int i = 0; i + len <= n; i++)
        for (int j = 0; j + len <= n; j++)
        {
          if (i)
            f[i][j] += f[i - 1][j];
          if (j)
            f[i][j] += f[i][j - 1];
          if (i && j)
            f[i][j] -= f[i - 1][j - 1];
          if (f[i][j] == diff || f[i][j] == diff + 1)
          {
            cout << 1 << endl;
            return 0;
          }
        }
    }
    cout << 2 << endl;
  }
}