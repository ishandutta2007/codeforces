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
    int n = s.size();
    s = " " + s;

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
      int isGood = 1, last = -1;
      for (int j = 1; j <= n; j++)
      {
        int expected = j > i;
        if (s[j] - '0' != expected)
        {
          if (j == last + 1)
          {
            isGood = 0;
            break;
          }
          last = j;
        }
      }

      ans |= isGood;
    }

    cout << (ans ? "YES" : "NO") << '\n';
  }
}