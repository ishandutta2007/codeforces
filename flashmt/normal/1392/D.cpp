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
    int n;
    string s;
    cin >> n >> s;
    if (s[0] == s[n - 1])
      for (int i = 0; i < n; i++)
        if (s[i] != s[0])
        {
          rotate(s.begin(), s.begin() + i, s.end());
          break;
        }

    int ans = 0;
    for (int i = 0; i < n;)
    {
      int j = i + 1;
      while (j < n && s[j] == s[i])
        j++;
      if (j - i == n) ans += (n + 2) / 3;
      else ans += (j - i) / 3;
      i = j;
    }
    cout << ans << endl;
  }
}