#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> next(26, -1), prev(26, -1), has(26);
  while (n--)
  {
    string s;
    cin >> s;
    for (char c : s)
      has[c - 'a'] = 1;
    for (int i = 0; i + 1 < size(s); i++)
    {
      int x = s[i] - 'a', y = s[i + 1] - 'a';
      if (next[x] < 0)
        next[x] = y;
      if (prev[y] < 0)
        prev[y] = x;
      if (next[x] != y || prev[y] != x)
      {
        cout << "NO\n";
        return 0;
      }
    }
  }

  string ans;
  int total = 0;
  vector<int> flag(26);
  for (int i = 0; i < 26; i++)
  {
    total += has[i];
    if (has[i] && prev[i] < 0)
      for (int j = i; j >= 0 && !flag[j]; j = next[j])
      {
        flag[j] = 1;
        ans += char(j + 'a');
      }
  }

  if (size(ans) != total) cout << "NO\n";
  else cout << ans << '\n';
}