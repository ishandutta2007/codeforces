#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int m, n, ans = 1, hasZero = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
      string s;
      cin >> s;
      for (char c : s)
        if (c == '#') ans = ans * 2 % BASE;
        else hasZero = 1;
    }
    ans = (ans + hasZero - 1 + BASE) % BASE;
    cout << ans << endl;
  }
}