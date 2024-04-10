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
    int n;
    string s;
    cin >> n >> s;
    s += 'z';
    for (int i = 0; i < n; i++)
      if ((!i && s[i] <= s[i + 1]) || (i && s[i] < s[i + 1]))
      {
        string t = s.substr(0, i + 1);
        cout << t;
        reverse(begin(t), end(t));
        cout << t << '\n';
        break;
      }
  }
}