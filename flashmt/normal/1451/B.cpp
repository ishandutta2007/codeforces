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
    int n, q;
    string s;
    cin >> n >> q >> s;
    while (q--)
    {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      string ans = "NO";
      for (int i = 0; i < l; i++)
        if (s[i] == s[l])
          ans = "YES";
      for (int i = r + 1; i < n; i++)
        if (s[i] == s[r])
          ans = "YES";
      cout << ans << endl;
    }
  }
}