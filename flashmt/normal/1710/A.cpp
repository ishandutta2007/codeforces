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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int &x : a)
      cin >> x;
    sort(rbegin(a), rend(a));

    int ans = 0;
    for (int turn : {0, 1})
    {
      long long has = 0, minHas = 0;
      for (int x : a)
        if (x >= n * 2)
        {
          has += x / n;
          minHas += 2;
          if (has >= m)
            break;
        }

      if (has >= m && minHas <= m)
        ans = 1;
      swap(m, n);
    }

    cout << (ans ? "Yes" : "No") << '\n';
  }
}