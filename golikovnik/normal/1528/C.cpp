//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

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

void solve(int) {
  int n;
  cin >> n;
  vector<vector<int>> g1(n), g2(n);
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    g1[x - 1].push_back(i);
  }
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    g2[x - 1].push_back(i);
  }
  vector<int> tin(n), tout(n);
  int timer = 0;
  {
    auto dfs = [&](auto&& dfs, int v) -> void {
      tin[v] = timer++;
      for (auto u : g2[v]) dfs(dfs, u);
      tout[v] = timer;
    };
    dfs(dfs, 0);
  }
  int ans = 0;
  set<pair<int, int>> st;
  auto dfs = [&](auto&& dfs, int v) -> void {
    auto it = st.lower_bound({tin[v], 0});
    int hisTin = -1;
    int hisTout = -1;
    if (it != st.begin()) {
      --it;
      if (it->second >= tout[v]) {
        hisTin = it->first;
        hisTout = it->second;
        st.erase(it);
      }
    }
    st.emplace(tin[v], tout[v]);
    smax(ans, int(st.size()));
    for (int u : g1[v]) {
      dfs(dfs, u);
    }
    st.erase({tin[v], tout[v]});
    if (hisTin >= 0) {
      st.emplace(hisTin, hisTout);
    }
  };
  dfs(dfs, 0);
  cout << ans << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int _tt = 1; _tt <= tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}