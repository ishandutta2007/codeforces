#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int m, n;
    string a[555];
    cin >> m >> n;
    for (int i = 0; i < m; i++)
      cin >> a[i];

    int startRow = 1;
    if (m % 3 == 1)
      startRow = 0;

    for (int j = 0; j < n; j++)
      a[startRow][j] = 'X';

    for (int i = startRow; i + 3 < m; i += 3)
    {
      int connected = 0;
      for (int j = 0; j < n; j++)
      {
        a[i + 3][j] = 'X';
        if ((a[i + 1][j] == 'X' || a[i + 2][j] == 'X') && !connected)
        {
          connected = 1;
          a[i + 1][j] = a[i + 2][j] = 'X';
        }
      }

      if (!connected)
        a[i + 1][0] = a[i + 2][0] = 'X';
    }

    for (int i = 0; i < m; i++)
      cout << a[i] << '\n';
  }
}