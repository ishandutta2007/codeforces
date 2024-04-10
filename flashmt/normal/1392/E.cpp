#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  long long a[25][25] = {0}, diagonal[55] = {0}, x = 1;
  cin >> n;
  for (int row = n - 1; row; row--)
  {
    a[row][n - 2] = diagonal[row + n - 2] = x;
    x *= 2;
  }
  for (int col = n - 3; col >= 0; col--)
  {
    a[1][col] = diagonal[col + 1] = x;
    x *= 2;
  }

  for (int i = 4; i <= n; i += 2)
  {
    for (int row = n - 1; row >= i - 1; row--)
      a[row][n - i] = diagonal[row + n - i];
    for (int col = 0; col < n - i; col++)
      a[i - 1][col] = diagonal[i - 1 + col];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << a[i][j] << ' ';
    cout << endl;
    cout.flush();
  }

  int q;
  cin >> q;
  while (q--)
  {
    long long v;
    cin >> v;
    vector<pair<int, int>> ans = {{0, 0}};
    int row = 0, col = 0;
    while (row < n - 1 || col < n - 1)
    {
      if (row == n - 1) col++;
      else if (col == n - 1) row++;
      else if (a[row + 1][col] < a[row][col + 1])
      {
        if (v < a[row][col + 1]) row++;
        else v -= a[row][++col];
      }
      else
      {
        if (v < a[row + 1][col]) col++;
        else v -= a[++row][col];
      }
      ans.push_back({row, col});
    }
    for (auto [x, y] : ans)
    {
      cout << x + 1 << ' ' << y + 1 << endl;
      cout.flush();
    }
  }
}