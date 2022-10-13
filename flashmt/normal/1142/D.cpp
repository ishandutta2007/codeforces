#include <bits/stdc++.h>
using namespace std;

int n, f[100100][11];
string s;

int dp(int i, int j)
{
  if (f[i][j] >= 0)
    return f[i][j];
  if (i == n - 1)
    return i;

  int c = s[i + 1] - '0';
  if (c >= j)
    return i;
  return f[i][j] = dp(i + 1, (c + 10 + j * (j - 1) / 2) % 11);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  n = s.size();

  memset(f, -1, sizeof f);
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--)
    if (s[i] != '0')
      ans += dp(i, s[i] - '0') - i + 1;
  cout << ans << endl;
}