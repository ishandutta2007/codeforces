#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const int N = 200200;

map<long long, long long> my[N], mz[N];

int isGood(map<long long, long long> &m, long long x, long long y)
{
  auto u = m.upper_bound(x);
  return u == begin(m) ? 0 : (--u)->second <= y;
}

void add(map<long long, long long> &m, long long x, long long y)
{
  auto u = m.upper_bound(x);
  if (u != begin(m) && prev(u)->second <= y)
    return;
  while (u != end(m) && u->second >= y)
    u = m.erase(u);
  m[x] = y;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long v;
  cin >> n >> v;
  vector<int> t(n);
  for (int &x : t)
    cin >> x;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  int ans = 0;
  for (int i = 0; i < n; i++)
    if (abs(a[i]) <= t[i] * v)
    {
      long long y = t[i] * v - a[i];
      long long z = t[i] * v + a[i];

      int low = 1, high = ans, f = 0;
      while (low <= high)
      {
        int mid = (low + high) / 2;
        if (isGood(my[mid], a[i], y) || isGood(mz[mid], -a[i], z))
        {
          f = mid;
          low = mid + 1;
        }
        else high = mid - 1;
      }

      ans = max(ans, ++f);
      add(my[f], a[i], y);
      add(mz[f], -a[i], z);
    }

  cout << ans << endl;
}