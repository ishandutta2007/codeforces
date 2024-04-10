#include <bits/stdc++.h>
using namespace std;

int f[555][1010];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    string s, t;
    cin >> s >> t;
    int m = size(s), n = size(t), ans = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        f[i][j] = 0;
    for (int i = 0; i < m; i++)
      for (int r = 0; r < n && i + r < m; r++)
        if (s[i + r] == t[r])
        {
          f[i + r][r] = 1;
          if (r == n - 1)
            ans = 1;
        }
        else break;

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (f[i][j])
          for (int k = j + 1; k < n; k++)
          {
            int ii = i - (k - j);
            if (ii >= 0 && s[ii] == t[k])
            {
              if (k == n - 1)
                ans = 1;
            }
            else break;
          }

    cout << (ans ? "YES\n" : "NO\n");
  }
}