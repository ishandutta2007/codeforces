//  Copyright 2022 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

int const S = int(1.1e6);
//  a - weights
//  sum(a) < S
bitset<S> knapsack(vector<int> const& a) {
  vector<int> cnt(S);
  for (int x : a) {
    ++cnt[x];
  }
  bitset<S> f;
  f[0] = 1;
  for (int x = 1; x < S; ++x) {
    int cx = cnt[x];
    if (cx == 0) {
      continue;
    }
    if (cx % 2 == 0) {
      f |= f << x;
      f |= f << x;
      if (cx != 2) {
        cnt[x * 2] += cx / 2 - 1;
      }
    } else {
      f |= f << x;
      if (cx != 1) {
        cnt[x * 2] += cx / 2;
      }
    }
  }
  return f;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; ++i) {
    int p; cin >> p; graph[p - 1].push_back(i); graph[i].push_back(p - 1);
  }
  vector<int> sz(n);
  auto dfs = [&](auto&& self, int v, int p = -1) -> void {
    sz[v] = 1;
    for (int u : graph[v]) {
      if (u != p) {
        self(self, u, v);
        sz[v] += sz[u];
      }
    }
  };
  dfs(dfs, 0);
  auto findCentroid = [&](int v) {
    int s = sz[v];
    int p = -1;
    while (true) {
      bool found = false;
      for (int u : graph[v]) {
        if (u != p && 2 * sz[u] > s) {
          p = v;
          v = u;
          found = true;
          break;
        }
      }
      if (!found) {
        return v;
      }
    }
    assert(false);
  };
  int c = findCentroid(0);
  ll ans = 0;
  dfs(dfs, c);
  for (int v = 0; v < n; ++v) {
    ans += sz[v];
  }
  vector<int> a;
  map<int, int> s;
  for (int u : graph[c]) {
    a.push_back(sz[u]);
    ++s[sz[u]];
  }
  auto f = knapsack(a);
  int cur = (n - 1) / 2;
  while (!f[cur]) --cur;
  ans += ll(cur) * (n - 1 - cur);
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}