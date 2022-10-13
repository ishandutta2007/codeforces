#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;
const string BAD[] = {"1100", "1010", "0111", "1111"};

int n, f[3030][3030], good[3030];
string s(3000, '$');

int calc(int l, int r)
{
  if (r < l)
    return 1;
  if (f[l][r] >= 0)
    return f[l][r];

  long long res = 0;
  string lastLetter;

  for (int k = 0; k < 4 && r - k >= l; k++)
  {
    lastLetter += s[r - k];
    if (find(BAD, BAD + 4, lastLetter) == BAD + 4)
      res += calc(l, r - k - 1);
  }

  f[l][r] = res % BASE;
  return f[l][r];
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
    good[i] = i;
  }

  for (int dif = 1; dif < n; dif++)
  {
    int lcp = 0;
    for (int i = 0; dif + i < n; i++)
    {
      if (s[i] == s[dif + i]) lcp++;
      else lcp = 0;
      good[dif + i] = min(good[dif + i], dif + i - lcp);
    }
  }

  long long ans = 0;
  memset(f, -1, sizeof f);
  for (int i = 0; i < n; i++)
  {
    for (int j = good[i]; j >= 0; j--)
      ans = (ans + calc(j, i)) % BASE;
    cout << ans << '\n';
  }
}