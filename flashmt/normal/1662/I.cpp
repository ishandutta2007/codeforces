#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const long long oo = 1LL << 50;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> p(n);
  for (auto &x : p)
    cin >> x;
  vector<long long> shops(m);
  for (auto &x : shops)
  {
    cin >> x;
    x *= 2;
  }

  sort(begin(shops), end(shops));
  map<long long, long long> bounds;
  for (int i = 0, j = 0; i < n; i++)
  {
    while (j < m && shops[j] < i * 200)
      j++;
    long long dist = oo;
    if (j < m)
      dist = min(dist, shops[j] - i * 200);
    if (j)
      dist = min(dist, i * 200 - shops[j - 1]);

    if (dist)
    {
      bounds[i * 200 - dist + 1] += p[i];
      bounds[i * 200 + dist] -= p[i];
    }
  }

  long long ans = 0, cur = 0;
  for (auto [k, v] : bounds)
  {
    cur += v;
    ans = max(ans, cur);
  }
  cout << ans << endl;
}