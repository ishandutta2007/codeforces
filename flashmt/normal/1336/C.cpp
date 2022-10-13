#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int main()
{
  string s, t;
  cin >> s >> t;
  int m = size(s), n = size(t);
  vector<vector<int>> f(m + 1, vector<int>(m + 1));
  for (int i = 0; i <= m; i++)
    f[i][i] = 1;
  for (int len = 1; len <= m; len++)
    for (int i = 0; i + len <= m; i++)
    {
      int j = i + len;
      if (i >= n || s[len - 1] == t[i])
        f[i][j] = (f[i][j] + f[i + 1][j]) % BASE;
      if (j - 1 >= n || s[len - 1] == t[j - 1])
        f[i][j] = (f[i][j] + f[i][j - 1]) % BASE;
    }

  int ans = 0;
  for (int i = n; i <= m; i++)
    ans = (ans + f[0][i]) % BASE;
  cout << ans << endl;
}