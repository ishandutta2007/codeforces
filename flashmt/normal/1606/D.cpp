#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int m, n;
  cin >> m >> n;
  vector<vector<int>> a(m, vector<int>(n));
  vector<vector<int>> maxRowPrefix = a, minRowPrefix = a;
  vector<vector<int>> maxRowSuffix = a, minRowSuffix = a;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

    minRowPrefix[i][0] = maxRowPrefix[i][0] = a[i][0];
    for (int j = 1; j < n; j++)
    {
      minRowPrefix[i][j] = min(minRowPrefix[i][j - 1], a[i][j]);
      maxRowPrefix[i][j] = max(maxRowPrefix[i][j - 1], a[i][j]);
    }

    minRowSuffix[i][n - 1] = maxRowSuffix[i][n - 1] = a[i][n - 1];
    for (int j = n - 2; j >= 0; j--)
    {
      minRowSuffix[i][j] = min(minRowSuffix[i][j + 1], a[i][j]);
      maxRowSuffix[i][j] = max(maxRowSuffix[i][j + 1], a[i][j]);
    }
  }

  vector<int> rowId(m);
  iota(begin(rowId), end(rowId), 0);
  sort(begin(rowId), end(rowId), [&](int u, int v) { return a[u][0] > a[v][0]; });

  for (int j = 1; j < n; j++)
  {
    vector<int> minLeft(m), maxLeft(m), minRight(m), maxRight(m);
    minLeft[0] = minRowPrefix[rowId[0]][j - 1];
    maxRight[0] = maxRowSuffix[rowId[0]][j];
    for (int i = 1; i < m; i++)
    {
      minLeft[i] = min(minLeft[i - 1], minRowPrefix[rowId[i]][j - 1]);
      maxRight[i] = max(maxRight[i - 1], maxRowSuffix[rowId[i]][j]);
    }

    minRight[m - 1] = minRowSuffix[rowId[m - 1]][j];
    maxLeft[m - 1] = maxRowPrefix[rowId[m - 1]][j - 1];
    for (int i = m - 2; i >= 0; i--)
    {
      minRight[i] = min(minRight[i + 1], minRowSuffix[rowId[i]][j]);
      maxLeft[i] = max(maxLeft[i + 1], maxRowPrefix[rowId[i]][j - 1]);
    }

    string rowColor(m, 'B');
    for (int i = 0; i + 1 < m; i++)
    {
      rowColor[rowId[i]] = 'R';
      if (maxLeft[i + 1] < minLeft[i] && maxRight[i] < minRight[i + 1])
      {
        cout << "YES\n";
        cout << rowColor << ' ' << j << '\n';
        return;
      }
    }
  }

  cout << "NO\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
    solve();
}