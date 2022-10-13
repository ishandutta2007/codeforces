#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int n, cnt[2020][3], c[2020][2020];
string s;

int main()
{
  cin >> s;
  n = s.size();
  s = " " + s;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < 3; j++)
      cnt[i][j] = cnt[i - 1][j];
    if (s[i] == '(') cnt[i][0]++;
    else if (s[i] == ')') cnt[i][1]++;
    else cnt[i][2]++;
  }

  for (int i = 0; i <= 2000; i++)
    for (int j = 0; j <= i; j++)
      c[i][j] = j ? (c[i - 1][j - 1] + c[i - 1][j]) % BASE : 1;

  long long ans = 0;
  for (int i = 1; i < n; i++)
    for (int d = 1; d <= min(i, n - i); d++)
    {
      int needOpen = d - cnt[i][0], needClose = d - (cnt[n][1] - cnt[i][1]);
      if (needOpen >= 0 && needClose >= 0)
      {
        long long ways = 1LL * c[cnt[i][2]][needOpen] * c[cnt[n][2] - cnt[i][2]][needClose] % BASE;
        ans = (ans + ways * d) % BASE;
      }
    }
  cout << ans << endl;
}