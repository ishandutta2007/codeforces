#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7, N = 2020;

int m, n, row[N][N], col[N][N], wayRow[N][N], wayCol[N][N], sumRow[N][N], sumCol[N][N];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  if (m == 1 && n == 1)
  {
    cout << 1 << endl;
    return 0;
  }
  for (int i = 1; i <= m; i++)
  {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++)
    {
      row[i][j] = row[i][j - 1] + (s[j - 1] == 'R');
      col[i][j] = col[i - 1][j] + (s[j - 1] == 'R');
    }
  }

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    {
      if (i == 1 && j == 1) wayRow[i][j] = wayCol[i][j] = 1;
      else
      {
        sumRow[i][j] = (sumRow[i][j] + sumRow[i][j - 1]) % BASE;
        wayRow[i][j] = sumRow[i][j];
        sumCol[i][j] = (sumCol[i][j] + sumCol[i - 1][j]) % BASE;
        wayCol[i][j] = sumCol[i][j];
      }

      int jj = n - (row[i][n] - row[i][j]);
      sumRow[i][j + 1] = (sumRow[i][j + 1] + wayCol[i][j]) % BASE;
      sumRow[i][jj + 1] = (sumRow[i][jj + 1] - wayCol[i][j] + BASE) % BASE;

      int ii = m - (col[m][j] - col[i][j]);
      sumCol[i + 1][j] = (sumCol[i + 1][j] + wayRow[i][j]) % BASE;
      sumCol[ii + 1][j] = (sumCol[ii + 1][j] - wayRow[i][j] + BASE) % BASE;
    }

  cout << (wayRow[m][n] + wayCol[m][n]) % BASE << endl;
}