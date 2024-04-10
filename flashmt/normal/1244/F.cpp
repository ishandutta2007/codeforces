#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int isSpecial()
{
  if (n % 2)
    return 0;
  for (int i = 1; i < n; i++)
    if (s[i] == s[i - 1])
      return 0;
  return 1;
}

void process(string &ans, int from, int to)
{
  if (from > to)
    return;

  char l = s[(from - 1) % n], r = s[(to + 1) % n];
  int len = to - from + 1 - k * 2;
  int center = (from + to) / 2;
  if (l == r)
  {
    for (int i = from; i <= to; i++)
      ans[i] = l;
    if (len > 0)
    {
      char cur = char(l ^ 'B' ^ 'W');
      for (int i = center - len / 2; i <= center + len / 2; i++)
      {
        ans[i] = cur;
        cur = char(cur ^ 'B' ^ 'W');
      }
    }
  }
  else
  {
    for (int i = from, j = to; i <= j; i++, j--)
    {
      ans[i] = l;
      ans[j] = r;
    }
    if (len > 0)
      for (int i = center - len / 2 + 1; i <= center + len / 2; i += 2)
      {
        ans[i] = r;
        ans[i + 1] = l;
      }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> s;
  if (isSpecial())
  {
    for (char c : s)
      cout << (k % 2 ? char(c ^ 'B' ^ 'W') : c);
    return 0;
  }

  int save = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == s[(i + 1) % n])
    {
      rotate(s.begin(), s.begin() + i, s.end());
      save = i;
      break;
    }

  string ans = s;
  for (int i = 2; i < n;)
    if (s[i] == s[i - 1]) i++;
    else
    {
      int j = i + 1;
      while (s[j % n] != s[(j - 1) % n])
        j++;
      process(ans, i, j - 2);
      i = j + 1;
    }

  if (save)
    rotate(ans.begin(), ans.begin() + n - save, ans.end());
  cout << ans << endl;
}