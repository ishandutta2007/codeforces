#include <bits/stdc++.h>
using namespace std;

int m, n, row[66][66], col[66][66];
string a[66];

int check2()
{
  if (a[1][1] == 'A' || a[1][n] == 'A' || a[m][1] == 'A' || a[m][n] == 'A')
    return 1;
  for (int i = 1; i <= m; i++)
    if (row[i][n] == n)
      return 1;
  for (int j = 1; j <= n; j++)
    if (col[m][j] == m)
      return 1;
  return 0;
}

int check3()
{
  return row[1][n] || row[m][n] || col[m][1] || col[m][n];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    cin >> m >> n;
    int sumAll = 0;
    for (int i = 1; i <= m; i++)
    {
      cin >> a[i];
      a[i] = " " + a[i];
      for (int j = 1; j <= n; j++)
      {
        row[i][j] = row[i][j - 1] + (a[i][j] == 'A');
        col[i][j] = col[i - 1][j] + (a[i][j] == 'A');
      }
      sumAll += row[i][n];
    }

    if (!sumAll) cout << "MORTAL\n";
    else if (sumAll == m * n) cout << "0\n";
    else if (row[1][n] == n || row[m][n] == n || col[m][1] == m || col[m][n] == m) cout << "1\n";
    else if (check2()) cout << "2\n";
    else if (check3()) cout << "3\n";
    else cout << "4\n";
  }
}