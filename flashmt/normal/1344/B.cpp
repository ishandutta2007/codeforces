#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vector<string> a(m);
  for (int i = 0; i < m; i++)
    cin >> a[i];

  int hasEmptyRow = 0;
  for (int i = 0; i < m; i++)
  {
    int minJ = n, maxJ = -1, cnt = 0;
    for (int j = 0; j < n; j++)
      if (a[i][j] == '#')
      {
        minJ = min(minJ, j);
        maxJ = max(maxJ, j);
        cnt++;
      }

    if (!cnt) hasEmptyRow = 1;
    else if (maxJ - minJ + 1 != cnt)
    {
      cout << -1 << endl;
      return 0;
    }
  }

  int hasEmptyCol = 0;
  for (int j = 0; j < n; j++)
  {
    int minI = m, maxI = -1, cnt = 0;
    for (int i = 0; i < m; i++)
      if (a[i][j] == '#')
      {
        minI = min(minI, i);
        maxI = max(maxI, i);
        cnt++;
      }

    if (!cnt) hasEmptyCol = 1;
    else if (maxI - minI + 1 != cnt)
    {
      cout << -1 << endl;
      return 0;
    }
  }

  if (hasEmptyCol ^ hasEmptyRow)
  {
    cout << -1 << endl;
    return 0;
  }

  int ans = 0;
  for (int i = 0; i < m; i++)
  {
    int isFirstRow = 1, hasBlack = 0;
    for (int j = 0; j < n; j++)
      if (a[i][j] == '#')
      {
        hasBlack = 1;
        if (i && a[i - 1][j] == '#')
          isFirstRow = 0;
      }
    ans += isFirstRow && hasBlack;
  }

  cout << ans << endl;
}