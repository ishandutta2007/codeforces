#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int BASE = 998244353;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int &x : a)
    {
      cin >> x;
      x--;
    }
    for (int &x : b)
    {
      cin >> x;
      if (x > 0)
        x--;
    }

    int isBad = 0;
    vector<int> freeA, active(n, 1);
    for (int i = 0; i < n; i++)
      if (b[i] < 0) freeA.push_back(a[i]);
      else if (a[i] > b[i] + k) isBad = 1;
      else active[b[i]] = 0;

    if (isBad)
    {
      cout << 0 << endl;
      continue;
    }

    sort(rbegin(freeA), rend(freeA));
    int cur = n - 1, cnt = 0;
    long long ans = 1;
    for (int x : freeA)
    {
      while (cur >= 0 && cur >= x - k)
        cnt += active[cur--];
      ans *= cnt--;
      ans %= BASE;
    }
    cout << ans << endl;
  }
}