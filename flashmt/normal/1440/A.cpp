#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int n, c0, c1, h, ans = 0;
    string s;
    cin >> n >> c0 >> c1 >> h >> s;
    for (char c : s)
      if (c == '0') ans += min(c0, c1 + h);
      else ans += min(c1, c0 + h);
    cout << ans << endl;
  }
}