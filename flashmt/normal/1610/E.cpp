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
    vector<long long> a(n);
    vector<int> same(n, 1);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (i && a[i] == a[i - 1])
        same[i] = same[i - 1] + 1;
    }


    int ans = 2;
    for (int i = 1; i < n; i++)
    {
      long long d = a[i] - a[i - 1];
      if (d == 0)
      {
        ans = max(ans, same[i]);
        continue;
      }

      int cur = i, cnt = same[i - 1] + 1;
      while (1)
      {
        int id = lower_bound(begin(a), end(a), a[cur] + d) - begin(a);
        if (id == n)
          break;
        cnt++;
        d = a[id] - a[i - 1];
        cur = id;
      }

      ans = max(ans, cnt);
    }

    cout << n - ans << '\n';
  }
}