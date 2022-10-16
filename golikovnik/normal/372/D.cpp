//  Copyright 2021 Nikita Golikov

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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k; cin >> n >> k; --k;
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int timer = 0;
  vector<int> tin(n), tout(n);
  vector<int> d(n);
  int const LOG = 18;
  vector up(LOG, vector<int>(n));
  vector<int> bytin(n);
  auto dfs = [&](auto&& self, int v, int p) -> void {
    up[0][v] = p;
    for (int i = 0; i + 1 < LOG; ++i) {
      up[i + 1][v] = up[i][up[i][v]];
    }
    tin[v] = timer++;
    bytin[tin[v]] = v;
    for (int u : graph[v]) {
      if (u != p) {
        d[u] = d[v] + 1;
        self(self, u, v);
      }
    }
    tout[v] = timer;
  };
  dfs(dfs, 0, 0);

  auto anc = [&](int v, int u) {
      return tin[v] <= tin[u] && tout[u] <= tout[v];
  };
  auto lca = [&](int v, int u) {
    if (anc(v, u)) return v;
    for (int i = LOG - 1; i >= 0; --i) {
      int pv = up[i][v];
      if (!anc(pv, u)) v = pv;
    }
    return up[0][v];
  };

  auto f = [&](int x, int y) {
    return d[lca(bytin[x], bytin[y])];
  };
  
  set<int> st;
  int ans = 0;
  auto insert = [&](int v) {
    ans += d[v];
    int tm = tin[v];
    auto it = st.lower_bound(tm);
    if (it != st.end() && it != st.begin()) {
      int nxt = *it;
      int prv = *prev(it);
      ans += f(prv, nxt);
      ans -= f(prv, tm);
      ans -= f(tm, nxt);
    } else if (it == st.end()) {
      if (!st.empty()) {
        ans -= f(*st.rbegin(), tm);
      }
    } else {
      assert(it == st.begin());
      assert(!st.empty());
      ans -= f(tm, *st.begin());
    }
    st.insert(tm);
  };
  auto erase = [&](int v) {
    ans -= d[v];
    int tm = tin[v];
    auto it = st.find(tm);
    if (it != st.begin()) {
      ans += f(*prev(it), tm);
    }
    if (it != prev(st.end())) {
      ans += f(tm, *next(it));
    }
    if (it != st.begin() && it != prev(st.end())) {
      ans -= f(*prev(it), *next(it));
    }
    st.erase(tm);
  };
  auto solve = [&]() {
    return ans - f(*st.rbegin(), *st.begin());
  };

  auto can = [&](int len) {
    st.clear();
    ans = 0;
    for (int i = 0; i < len; ++i) {
      insert(i);
    }
    if (solve() <= k) {
      return true;
    }
    for (int i = len; i < n; ++i) {
      insert(i);
      erase(i - len);
      if (solve() <= k) {
        return true;
      }
    }
    return false;
  };

  int left = 0;
  int right = n + 1;
  while (left + 1 != right) {
    int mid = (left + right) / 2;
    (can(mid) ? left : right) = mid;
  }
  cout << left << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}