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
    int u, v;
    cin >> u >> v;
    if (u > v || __builtin_popcount(u) < __builtin_popcount(v))
    {
      cout << "NO\n";
      continue;
    }

    int ans = 1;
    for (int i = 0, j = 0; i < 30; i++)
      if (v >> i & 1)
      {
        while (j <= i && !(u >> j & 1))
          j++;
        if (j > i)
        {
          ans = 0;
          break;
        }
        j++;
      }

    cout << (ans ? "YES" : "NO") << '\n';
  }
}