#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, a, b, lcs[5050][5050];
string s;

int main()
{
  cin >> n >> a >> b >> s;
  s = " " + s;
  for (int d = 1; d < n; d++)
    for (int i = 1; i + d <= n; i++)
      if (s[i] == s[i + d]) lcs[i][i + d] = lcs[i - 1][i + d - 1] + 1;
      else lcs[i][i + d] = 0;

  vector<int> f(n + 1, oo);
  f[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    f[i] = f[i - 1] + a;
    for (int j = i - 1; j; j--)
      if (lcs[j][i])
        f[i] = min(f[i], f[max(j, i - lcs[j][i])] + b);
  }

  cout << f[n] << endl;
}