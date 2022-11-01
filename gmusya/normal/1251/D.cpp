#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
vector <int> p;
vector <ll> l, r;

ll can(ll m) {
  int cnt = 0;
  ll cost = 0;
  for (int id : p)
    if (l[id] > m || r[id] < m)
      cost += l[id], cnt += (l[id] > m);
  for (int id : p) {
    cost = min(cost, (ll)2e15);
    if (l[id] > m || r[id] < m)
      continue;
    if (cnt == (n + 1) / 2)
      cost += l[id];
    else
      cnt++, cost += m;
  }
  if (cnt != (n + 1) / 2)
    cost = 2e15;
  return cost;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll s;
    cin >> n >> s;
    l.assign(n, 0), r.assign(n, 0), p.assign(n, 0);
    for (int i = 0; i < n; i++)
      cin >> l[i] >> r[i];
    for (int i = 0; i < n; i++)
      p[i] = i;
    sort(p.begin(), p.end(), [&](int i, int j) {
      return l[i] > l[j];
    });
    ll L = l[p[n / 2]];
    while (can(L) > s)
      t++;
    ll R = s;
    while (L != R) {
      ll M = (L + R + 1) / 2;
      ll f = can(M);
      if (f > s)
        R = M - 1;
      else
        L = M;
    }
    cout << L << '\n';
  }
  return 0;
}