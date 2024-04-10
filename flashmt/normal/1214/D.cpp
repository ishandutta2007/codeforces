#include <bits/stdc++.h>
using namespace std;
const int N = 1000100;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, n;
  string s[N];
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    cin >> s[i];

  vector<vector<int>> flag = vector<vector<int>>(m, vector<int>(n, 0));
  flag[0][0] = 1;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (s[i][j] == '.' && flag[i][j])
      {
        if (i + 1 < m && s[i + 1][j] == '.')
          flag[i + 1][j] = 1;
        if (j + 1 < n && s[i][j + 1] == '.')
          flag[i][j + 1] = 1;
      }

  flag[m - 1][n - 1] |= 2;
  for (int i = m - 1; i >= 0; i--)
    for (int j = n - 1; j >= 0; j--)
      if (s[i][j] == '.' && flag[i][j] >= 2)
      {
        if (i && s[i - 1][j] == '.')
          flag[i - 1][j] |= 2;
        if (j && s[i][j - 1] == '.')
          flag[i][j - 1] |= 2;
      }

  if (flag[m - 1][n - 1] != 3) cout << 0 << endl;
  else
  {
    vector<int> diagonal(m + n, 0);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        diagonal[i + j] += flag[i][j] == 3;

    for (int i = 1; i < m + n - 2; i++)
      if (diagonal[i] == 1)
      {
        cout << 1 << endl;
        return 0;
      }

    cout << 2 << endl;
  }
}