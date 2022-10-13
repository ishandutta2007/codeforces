#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
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
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    int ans = 1;
    for (int i = 1; i < m; i++)
      if (a[n - i] != b[m - i])
        ans = 0;

    if (ans)
    {
      ans = 0;
      for (int i = n - m; i >= 0; i--)
        if (a[i] == b[0])
          ans = 1;
    }

    cout << (ans ? "YES" : "NO") << '\n';
  }
}