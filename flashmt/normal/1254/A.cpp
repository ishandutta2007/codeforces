#include <bits/stdc++.h>
using namespace std;

char encode(int i)
{
  if (i < 10)
    return char(i + '0');
  i -= 10;
  if (i < 26)
    return char(i + 'A');
  i -= 26;
  return char(i + 'a');
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int m, n, k, rice = 0;
    string a[111];
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++)
    {
      cin >> a[i];
      for (char c : a[i])
        rice += c == 'R';
    }

    int x = 0, y = 0, dir = 1;
    vector<string> ans(m, string(n, '.'));
    for (int i = 0; i < k; i++)
    {
      int need = rice / k;
      if (i < rice % k)
        need++;
      while (need > 0)
      {
        ans[x][y] = encode(i);
        if (a[x][y] == 'R')
          need--;
        if (y + dir >= 0 && y + dir < n) y += dir;
        else
        {
          x++;
          dir = -dir;
        }
      }
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
        if (ans[i][j] == '.')
          ans[i][j] = encode(k - 1);
      cout << ans[i] << '\n';
    }
  }
}