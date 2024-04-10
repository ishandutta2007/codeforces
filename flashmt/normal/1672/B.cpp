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
    int x = 0, ans = 1;
    for (char c : s)
      if (c == 'A') x++;
      else if (!x) ans = 0;
      else x--;
    cout << (ans && s.back() == 'B' ? "YES" : "NO") << '\n';
  }
}