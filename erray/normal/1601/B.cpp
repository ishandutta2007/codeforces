// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    b[i] = i + b[i];
  }

  debug(b);
  
  queue<array<int, 5>> que;
  set<int> act;
  for (int i = 0; i < n; ++i) {
    act.insert(i);
  }
  const int inf = int(1e9);
  int ans = inf;
  que.push({n - 1, n, -1, 0, 0});
  vector<int> par(n, -1);
  int from = 0;
  while (!que.empty()) {
    auto[l, r, parent, type, cost] = que.front();
    que.pop();
    debug(l, r, parent, type, cost);
    if (l == -1 && cost < ans) {
      ans = cost;
      from = parent;
    }

    if (l == -1) {
      continue;
    }
    if (type == 0) {
      que.push({l - a[l], l, parent, 1, cost});
    } else {
      auto R = act.lower_bound(r);
      auto L = act.lower_bound(l);
      while (L != R) {
        int x = *L;
        par[x] = parent;
        debug(x);
        que.push({b[x], b[x] + 1, x, 0, cost + 1});
        act.erase(L);
        R = act.lower_bound(r);
        L = act.lower_bound(l);
      }
    }
  }

  if (ans == inf) {
    cout << -1 << '\n';
    return 0;
  }

  vector<int> res = {0};
  while (from != -1) {
    res.push_back(from + 1);
    from = par[from];
  }
  reverse(res.begin(), res.end());
  cout << int(res.size()) << '\n';
  for (auto e : res) {
    cout << e << ' ';
  }
}