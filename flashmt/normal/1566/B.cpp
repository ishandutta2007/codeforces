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
    int n = size(s);
    int minZero = n, maxZero = -1;
    for (int i = 0; i < n; i++)
      if (s[i] == '0')
      {
        minZero = min(minZero, i);
        maxZero = i;
      }

    if (maxZero < 0) cout << "0\n";
    else
    {
      int ans = 1;
      for (int i = minZero; i <= maxZero; i++)
        if (s[i] == '1')
          ans = 2;
      cout << ans << '\n';
    }
  }
}