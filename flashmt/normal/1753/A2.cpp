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
    int n;
    cin >> n;
    vector<int> a(n), id;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (i % 2)
        a[i] = -a[i];
      if (a[i] != 0)
        id.push_back(i);
    }

    if (size(id) % 2) cout << -1 << endl;
    else
    {
      vector<int> stops;
      for (int i = 0, parity = 1; i < size(id); i += 2)
      {
        int x = id[i], y = id[i + 1];
        if (a[x] != a[y])
          continue;

        if (x % 2 == parity)
        {
          stops.push_back(x);
          stops.push_back(x + 1);
        }
        else if (y % 2 == parity)
        {
          stops.push_back(y);
          stops.push_back(y + 1);
        }
        else
        {
          stops.push_back(y - 1);
          stops.push_back(y + 1);
          parity ^= 1;
        }
      }
      if (empty(stops) || stops.back() != n)
        stops.push_back(n);

      cout << size(stops) << '\n';
      int cur = 1;
      for (int x : stops)
      {
        cout << cur << ' ' << x << '\n';
        cur = x + 1;
      }
    }
  }
}