#include <bits/stdc++.h>
using namespace std;
const int LEN = 8;

set <string> bad[LEN + 1];

int isBad(string s)
{
  for (int i = 0; i < s.size(); i++)
    for (int k = 1; i - k >= 0 && i + k < s.size(); k++)
      if (s[i] == s[i - k] && s[i] == s[i + k])
        return 0;
  return 1;
}

void preCalc()
{
  for (int n = 1; n <= LEN; n++)
    for (int mask = 0; mask < 1 << n; mask++)
    {
      string s;  
      for (int i = 0; i < n; i++)
        s += char('0' + (mask >> i & 1));
      if (isBad(s))
        bad[n].insert(s);
    }
}

int main()
{
  ios::sync_with_stdio(0);
  preCalc();
  string s;
  cin >> s;
  int n = s.size();
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j <= LEN && i + j <= n; j++)
      ans += 1 - bad[j].count(s.substr(i, j));
    if (i + LEN < n)
      ans += n - i - LEN;
  }
  cout << ans << endl;
}