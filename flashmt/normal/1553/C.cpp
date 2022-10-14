#include <bits/stdc++.h>
using namespace std;

int ans;

void go(int i, string s)
{
  if (i == 10)
  {
    int diff = 0, remFirst = 5, remSecond = 5;
    for (int j = 0; j < 10; j++)
    {
      if (j % 2 == 0)
      {
        diff += s[j] - '0';
        remFirst--;
      }
      else
      {
        diff -= s[j] - '0';
        remSecond--;
      }

      if (diff > remSecond || -diff > remFirst)
        ans = min(ans, j + 1);
    }
  }
  else if (s[i] != '?') go(i + 1, s);
  else
  {
    s[i] = '0';
    go(i + 1, s);
    s[i] = '1';
    go(i + 1, s);
    s[i] = '?';
  }
}

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
    ans = 10;
    go(0, s);
    cout << ans << '\n';
  }
}