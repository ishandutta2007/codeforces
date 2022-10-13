#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
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
    int n;
    cin >> n;
    vector<vector<int>> a(n * 2 + 1, vector<int>(n * 2 + 1));
    long long targetCost = 0;
    for (int i = 0; i < n * 2; i++)
      for (int j = 0; j < n * 2; j++)
      {
        cin >> a[i][j];
        if (i >= n && j >= n)
          targetCost += a[i][j];
      }

    int minCell = a[0][n];
    minCell = min(minCell, a[0][n * 2 - 1]);
    minCell = min(minCell, a[n - 1][n]);
    minCell = min(minCell, a[n - 1][n * 2 - 1]);
    minCell = min(minCell, a[n][0]);
    minCell = min(minCell, a[n][n - 1]);
    minCell = min(minCell, a[n * 2 - 1][0]);
    minCell = min(minCell, a[n * 2 - 1][n - 1]);

    cout << targetCost + minCell << endl;
  }
}