#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int BASE = 998244353;
const int MAX = 3e5 + 5;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++)
    cin >> l[i] >> r[i];

  set<int> s;
  for (int i = 0; i <= MAX; i++)
    s.insert(i);

  vector<long long> p2(n), p3(n);
  p2[0] = p3[0] = 1;
  for (int i = 1; i < n; i++)
  {
    p2[i] = p2[i - 1] * 2 % BASE;
    p3[i] = p3[i - 1] * 3 % BASE;
  }

  long long ans = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    int cnt = 0;
    auto u = s.lower_bound(l[i]);
    while (*u <= r[i])
    {
      cnt++;
      u = s.erase(u);
    }
    ans = (ans + p3[max(i - 1, 0)] * p2[min(n - i, n - 1)] % BASE * cnt) % BASE;
  }
  cout << ans << endl;
}