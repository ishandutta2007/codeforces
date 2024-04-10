#include <bits/stdc++.h>
using namespace std;
const int A[4][4] = {
  {8, 9, 1, 13},
  {3, 12, 7, 5},
  {0, 2, 4, 11},
  {6, 10, 15, 14}
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int ans[1010][1010], row[1010] = {0}, col[1010] = {0};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      int offset = ((i / 4) * (n / 4) + (j / 4)) * 16;
      ans[i][j] = offset + A[i % 4][j % 4];
      row[i] ^= ans[i][j];
      col[j] ^= ans[i][j];
    }

  for (int i = 1; i < n; i++)
  {
    assert(row[i] == row[i - 1]);
    assert(col[i] == col[i - 1]);
  }
  assert(row[0] == col[0]);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cout << ans[i][j] << " \n"[j == n - 1];
}