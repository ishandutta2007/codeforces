#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
const int N = 1e5 + 5;
const long long oo = 1LL << 60;

using ll = long long;

struct Line {
  mutable ll k, m, p; // y = kx + m
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  // query maximum value
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  const ll inf = LLONG_MAX;

  ll div(ll a, ll b) { // floored division
    return a / b - ((a ^ b) < 0 && a % b);
  }

  bool isect(iterator x, iterator y) {
    if (y == end()) { x->p = inf; return false; }
    if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
    else x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }

  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }

  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};

vector<pair<int, int>> a[N];

void dijkstra(vector<long long> &dist)
{
  priority_queue<pair<long long, int>> q;
  for (int i = 0; i < size(dist); i++)
    q.push({-dist[i], i});
  while (!empty(q))
  {
    auto [curDist, x] = q.top();
    q.pop();
    if (-curDist != dist[x])
      continue;
    for (auto [y, w] : a[x])
      if (dist[x] + w < dist[y])
      {
        dist[y] = dist[x] + w;
        q.push({-dist[y], y});
      }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  while (m--)
  {
    int u, v, w;
    cin >> u >> v >> w;
    a[--u].push_back({--v, w});
    a[v].push_back({u, w});
  }

  vector<long long> dist(n, oo);
  dist[0] = 0;
  dijkstra(dist);
  for (int turn = 1; turn <= k; turn++)
  {
    LineContainer lc;
    auto distL = dist;
    for (int i = 0; i < n; i++)
    {
      if (i)
        distL[i] = min(distL[i], 1LL * i * i - lc.query(i));
      lc.add(2LL * i, -dist[i] - 1LL * i * i);
    }

    auto distR = dist;
    lc.clear();
    for (int i = n - 1; i >= 0; i--)
    {
      if (i < n - 1)
        distR[i] = min(distR[i], 1LL * i * i - lc.query(i));
      lc.add(2LL * i, -dist[i] - 1LL * i * i);
    }

    for (int i = 0; i < n; i++)
      dist[i] = min({dist[i], distL[i], distR[i]});
    dijkstra(dist);
  }

  for (auto x : dist)
    cout << x << ' ';
}