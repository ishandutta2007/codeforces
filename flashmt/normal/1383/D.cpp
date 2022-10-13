#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vector<vector<int>> a(m, vector<int>(n));
  vector<int> maxRow(m), maxCol(n);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
      a[i][j]--;
      maxRow[i] = max(maxRow[i], a[i][j]);
      maxCol[j] = max(maxCol[j], a[i][j]);
    }

  vector<int> isMaxRow(m * n), isMaxCol(m * n);
  for (int i = 0; i < m; i++)
    isMaxRow[maxRow[i]] = 1;
  for (int i = 0; i < n; i++)
    isMaxCol[maxCol[i]] = 1;

  vector<vector<int>> ans(m, vector<int>(n, -1));
  vector<int> boundRow(m), boundCol(n);
  int upperRow = m - 1, upperCol = n;
  int lowerRow = m, lowerCol = n - 1;
  for (int value = m * n - 1, row = m, col = n; value >= 0; value--)
    if (isMaxCol[value] && isMaxRow[value])
    {
      row--;
      col--;
      ans[row][col] = value;
      boundRow[row] = col;
      boundCol[col] = row;
    }
    else if (isMaxCol[value])
    {
      col--;
      ans[row][col] = value;
      boundCol[col] = row;
    }
    else if (isMaxRow[value])
    {
      row--;
      ans[row][col] = value;
      boundRow[row] = col;
    }
    else
    {
      int found = 0;
      while (lowerCol >= col && !found)
        if (lowerRow == m) lowerRow = boundCol[--lowerCol] + 1;
        else
        {
          ans[lowerRow++][lowerCol] = value;
          found = 1;
        }

      while (upperRow >= row && !found)
        if (upperCol == n) upperCol = boundRow[--upperRow] + 1;
        else
        {
          ans[upperRow][upperCol++] = value;
          found = 1;
        }

      if (!found)
      {
        cout << -1 << endl;
        return 0;
      }
    }

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cout << ans[i][j] + 1 << " \n"[j == n - 1];
}