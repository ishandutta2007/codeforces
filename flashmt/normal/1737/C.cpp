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
    int n, r[3], c[3], x, y;
    cin >> n;
    for (int i = 0; i < 3; i++)
      cin >> r[i] >> c[i];
    cin >> x >> y;

    int mid = 0;
    for (int i = 0; i < 3; i++)
    {

      int j = (i + 1) % 3, k = (i + 2) % 3;
      if (r[j] != r[k] && c[j] != c[k])
      {
        mid = i;
        break;
      }
    }

    int dx = abs(r[mid] - x), dy = abs(c[mid] - y);
    int ans = 0;
    for (int i = 0; i < 3; i++)
      if (x == r[i] && y == c[i])
        ans = 1;

    if (ans) cout << "YES\n";
    else if (dx % 2 && dy % 2) cout << "NO\n";
    else
    {
      int isCorner = 0;
      for (int i : {1, n})
        for (int j : {1, n})
          if (r[mid] == i && c[mid] == j)
            isCorner = 1;

      if (!isCorner) ans = 1;
      else ans = x == r[mid] || y == c[mid];
      cout << (ans ? "YES" : "NO") << '\n';
    }
  }
}