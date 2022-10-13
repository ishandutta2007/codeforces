#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int oo = 1LL << 30;
const double EPS = 1e-6;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), nextId(n);
  for (int &x : a)
    cin >> x;
  a.push_back(oo);
  iota(begin(nextId), end(nextId), 0);

  function<int(int, int)> go = [&](int i, int d)
  {
    if (nextId[i] != i)
      return nextId[i] = go(nextId[i], d);
    if (a[i + 1] - a[i] > d)
      return i;
    return nextId[i] = go(i + 1, d);
  };

  for (int d = 1; d <= a[n - 1]; d++)
  {
    long long l = max(0LL, 1LL * d * d - a[0]), r = 1LL * d * d + d - a[0];
    if (r < 0)
      continue;

    for (int i = 0; i < n && l <= r;)
    {
      int j = go(i, d);
      int dd = int(sqrt(a[i] + r) + EPS);
      l = max(l, 1LL * dd * dd - a[i]);
      r = min(r, 1LL * dd * dd + dd - a[j]);
      i = j + 1;
    }

    if (l <= r)
    {
      cout << l << endl;
      return 0;
    }
  }
}