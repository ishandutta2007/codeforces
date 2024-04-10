#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    string s, t;
    cin >> s >> t;
    vector<int> cnt(26);
    for (char c : t)
      cnt[c - 'A']++;
    string ss;
    for (int i = size(s) - 1; i >= 0; i--)
      if (cnt[s[i] - 'A'])
      {
        ss += s[i];
        cnt[s[i] - 'A']--;
      }
    reverse(begin(ss), end(ss));
    cout << (ss == t ? "YES" : "NO") << '\n';
  }
}