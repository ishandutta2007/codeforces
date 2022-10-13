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
    string s;
    cin >> s;
    int n = size(s);
    vector<int> lastId(26, n);
    for (int i = 0; i < n; i++)
      lastId[s[i] - 'a'] = i;

    int ans = n;
    for (int x : lastId)
      ans = min(ans, x);
    cout << s.substr(ans, n - ans) << '\n';
  }
}