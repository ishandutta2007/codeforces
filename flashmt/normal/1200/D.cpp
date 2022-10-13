#include <bits/stdc++.h>
using namespace std;

int n, k, row[2020][2020], col[2020][2020], minRow[2020], maxRow[2020];

void updateRow(int i, int addRow[], int v)
{
  if (minRow[i] > n) addRow[k] += v;
  else if (maxRow[i] - minRow[i] < k)
  {
    addRow[max(maxRow[i], k)] += v;
    if (minRow[i] + k <= n)
      addRow[minRow[i] + k] -= v;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    minRow[i] = n + 1;
  for (int i = 1; i <= n; i++)
  {
    cin >> s;
    for (int j = 1; j <= n; j++)
    {
      row[i][j] = row[i][j - 1];
      col[j][i] = col[j][i - 1];
      if (s[j - 1] == 'B')
      {
        row[i][j]++;
        col[j][i]++;
        minRow[i] = min(minRow[i], j);
        maxRow[i] = j;
      }
    }
  }

  int u[2020] = {0}, d[2020] = {0}, l[2020] = {0}, r[2020] = {0};
  for (int i = 1; i <= n; i++)
    u[i] = u[i - 1] + (row[i][n] == 0);
  for (int i = n; i; i--)
    d[i] = d[i + 1] + (row[i][n] == 0);
  for (int i = 1; i <= n; i++)
    l[i] = l[i - 1] + (col[i][n] == 0);
  for (int i = n; i; i--)
    r[i] = r[i + 1] + (col[i][n] == 0);


  int ans = 0, addRow[2020] = {0};
  // Add first k - 1 rows
  for (int i = 1; i < k; i++)
    updateRow(i, addRow, 1);

  for (int i = k; i <= n; i++)
  {
    int newWhiteCol = 0, newWhiteRow = 0;
    // add first k - 1 cols
    for (int j = 1; j < k; j++)
      if (col[j][i] - col[j][i - k] == col[j][n])
        newWhiteCol++;

    // add current row
    updateRow(i, addRow, 1);

    for (int j = k; j <= n; j++)
    {
      // add current col
      if (col[j][i] - col[j][i - k] == col[j][n])
        newWhiteCol++;
      // add precomputed rows
      newWhiteRow += addRow[j];

      ans = max(ans, newWhiteCol + newWhiteRow + u[i - k] + d[i + 1] + l[j - k] + r[j + 1]);

      // remove leftmost col
      if (col[j - k + 1][i] - col[j - k + 1][i - k] == col[j - k + 1][n])
        newWhiteCol--;
    }

    // remove leftmost row
    updateRow(i - k + 1, addRow, -1);
  }

  cout << ans << endl;
}