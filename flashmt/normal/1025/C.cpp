#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  int n = s.size();

  int ans = 1, cur = 1;
  for (int i = 1; i < n; i++)
    if (s[i] != s[i - 1]) ans = max(ans, ++cur);
    else cur = 1;

  if (s[0] != s.back())
  {
    cur++;
    for (int i = 1; i < n; i++)
      if (s[i] != s[i - 1]) cur++;
      else break;
    ans = max(ans, cur);
  }

  ans = min(ans, n);
  cout << ans << endl;
}