#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, string s)
{
  int cntAParity = 0; // a <= len < 2b
  int len2B = 0; // 2b <= len
  s += 'X';
  for (int i = 0, len = 0; i < s.size(); i++)
    if (s[i] == '.') len++;
    else
    {
      if (len >= b * 2)
      {
        if (len2B)
          return 0;
        len2B = len;
      }
      else if (len >= a) cntAParity ^= 1;
      else if (len >= b) return 0;
      len = 0;
    }

  if (!len2B)
    return cntAParity;

  for (int i = 0; i + a <= len2B; i++)
  {
    int j = len2B - i - a;
    if (i >= b * 2 || b <= i && i < a)
      continue;
    if (j >= b * 2 || b <= j && j < a)
      continue;
    if (cntAParity ^ (i >= a) ^ (j >= a) ^ 1)
      return 1;
  }
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int a, b;
    string s;
    cin >> a >> b >> s;
    cout << (solve(a, b, s) ? "YES\n" : "NO\n");
  }
}