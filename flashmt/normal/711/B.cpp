#include <bits/stdc++.h>
using namespace std;

int n, x, y;
long long row[500], col[500], ans, a[500][500];

int valid()
{
  if (ans <= 0)
    return 0;
  row[x] += ans;
  col[y] += ans;
  a[x][y] = ans;
  for (int i = 1; i < n; i++)
    if (row[i] != row[i - 1] || col[i] != col[i - 1])
      return 0;
  if (row[0] != col[0])
    return 0;
  long long diagonal1 = 0, diagonal2 = 0;
  for (int i = 0; i < n; i++)
  {
    diagonal1 += a[i][i];
    diagonal2 += a[i][n - 1 - i];
  }
  return diagonal1 == row[0] && diagonal2 == row[0];
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
      row[i] += a[i][j];
      col[j] += a[i][j];
      if (!a[i][j])
      {
        x = i;
        y = j;
      }
    }

  if (n == 1) cout << 1 << endl;
  else 
  {
    if (x) ans = row[0] - row[x];
    else ans = row[1] - row[x];
    cout << (valid() ? ans : -1) << endl;
  }
}