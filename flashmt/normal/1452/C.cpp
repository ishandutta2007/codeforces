#include <bits/stdc++.h>
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
    int x = 0, y = 0, ans = 0;
    for (char c : s)
      if (c == '(') x++;
      else if (c == ')')
      {
        if (x)
        {
          ans++;
          x--;
        }
      }
      else if (c == '[') y++;
      else if (y)
      {
        ans++;
        y--;
      }

    cout << ans << endl;
  }
}