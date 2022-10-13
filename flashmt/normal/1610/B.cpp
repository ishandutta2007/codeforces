#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    auto isPalin = [&](vector<int> &b)
    {
      int m = size(b);
      for (int i = 0; i < m - 1 - i; i++)
        if (b[i] != b[m - 1 - i])
          return 0;
      return 1;
    };

    if (isPalin(a)) cout << "YES\n";
    else
    {
      int ans = 0;
      for (int i = 0; i < n; i++)
        if (a[i] != a[n - 1 - i])
        {
          vector<int> b, c;
          for (int j = 0; j < n; j++)
          {
            if (a[j] != a[i])
              b.push_back(a[j]);
            if (a[j] != a[n - 1 - i])
              c.push_back(a[j]);
          }
          ans = isPalin(b) || isPalin(c);
          break;
        }

      cout << (ans ? "YES" : "NO") << '\n';
    }
  }
}