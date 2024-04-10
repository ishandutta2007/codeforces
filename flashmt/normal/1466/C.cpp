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
    int ans = 0, flag[256] = {0};
    for (int i = 1; i < s.size(); i++)
      if (s[i] == s[i - 1] || (i >= 2 && s[i] == s[i - 2]))
      {
        for (int j = i - 2; j <= i + 2; j++)
          if (j >= 0 && j < s.size())
            flag[s[j]] = i;
        ans++;

        for (char c = 'a'; c <= 'z'; c++)
          if (flag[c] != i)
          {
            s[i] = c;
            break;
          }
      }

    cout << ans << '\n';
  }
}