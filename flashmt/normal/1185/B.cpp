#include <bits/stdc++.h>
using namespace std;

int check(string s, string t)
{
  int j = 0;
  for (int i = 0; i < s.size(); i++)
    if (j >= t.size() || s[i] != t[j]) return 0;
    else
    {
      j++;
      if (i + 1 < s.size() && s[i] == s[i + 1])
        continue;
      while (j < t.size() && s[i] == t[j])
        j++;
    }
  return j == t.size();
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--)
  {
    string s, t;
    cin >> s >> t;
    cout << (check(s, t) ? "YES\n" : "NO\n");
  }
}