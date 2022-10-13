#include <bits/stdc++.h>
using namespace std;

int n, k, d[3][333];
string a[3];

int canMove(int i, int j, int turn)
{
  if (j + turn * 2 >= n) return 1;
  return a[i][j + turn * 2] == '.' || a[i][j + turn * 2] == 's';
}

int main()
{
  ios::sync_with_stdio(0);
  int test;
  cin >> test;
  while (test--)
  {
    cin >> n >> k;
    memset(d, 0, sizeof d); 
    for (int i = 0; i < 3; i++)
    {
      cin >> a[i];
      if (a[i][0] == 's')
        d[i][0] = 1;
    }

    for (int j = 0; j < n; j++)
      for (int i = 0; i < 3; i++)
        if (d[i][j] && canMove(i, j + 1, j))
          for (int ii = i - 1; ii <= i + 1; ii++)
            if (ii >= 0 && ii < 3 && canMove(ii, j + 1, j) && canMove(ii, j + 1, j + 1))
              d[ii][j + 1] = 1;

    cout << (d[0][n - 1] || d[1][n - 1] || d[2][n - 1] ? "YES" : "NO") << endl;
  }
}