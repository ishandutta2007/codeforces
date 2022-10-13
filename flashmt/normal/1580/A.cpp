#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> rows(m + 1, vector<int>(n + 1));
    vector<vector<int>> cols(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= m; i++)
    {
      string s;
      cin >> s;
      s = " " + s;
      for (int j = 1; j <= n; j++)
      {
        rows[i][j] = rows[i][j - 1] + (s[j] == '0');
        cols[j][i] = cols[j][i - 1] + (s[j] == '0');
      }
    }

    int ans = oo, sumMid[444];
    for (int j = 1; j < n; j++)
      for (int jj = j + 3; jj <= n; jj++)
      {
        int minRow = oo;
        sumMid[0] = 0;
        for (int i = 1; i <= m; i++)
        {
          sumMid[i] = sumMid[i - 1] + (jj - 1 - j) - (rows[i][jj - 1] - rows[i][j]);
          if (i > 4)
          {
            int toUpdate = rows[i - 4][jj - 1] - rows[i - 4][j];
            toUpdate -= cols[jj][i - 4] + cols[j][i - 4];
            toUpdate -= sumMid[i - 4];
            minRow = min(minRow, toUpdate);
          }
          ans = min(ans, cols[j][i - 1] + cols[jj][i - 1] + rows[i][jj - 1] - rows[i][j] + sumMid[i - 1] + minRow);
        }
      }

    cout << ans << '\n';
  }
}