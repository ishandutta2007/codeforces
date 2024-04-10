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

void solveTest() {
  int n; cin >> n;
  struct edge {
    int to;
    int a;
    int b;
  };
  vector<vector<edge>> graph(n);
  for (int i = 1; i < n; ++i) {
    int p, a, b;
    cin >> p >> a >> b;
    --p;
    graph[p].push_back({i, a, b});
  }
  vector<int> ans(n);
  vector<ll> st;
  auto dfs = [&](auto&& self, int v, ll sa = 0, ll sb = 0) -> void {
    for (auto e : graph[v]) {
      sa += e.a;
      sb += e.b;
      st.push_back(sb);
      ans[e.to] = upper_bound(st.begin(), st.end(), sa) - st.begin();
      self(self, e.to, sa, sb);
      sa -= e.a;
      sb -= e.b;
      st.pop_back();
    }
  };
  dfs(dfs, 0);
  for (int x = 1; x < n; ++x) {
    cout << ans[x] << ' ';
  }
  cout << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _tests;
  cin >> _tests;
  for (int _tt = 1; _tt <= _tests; ++_tt) {
    solveTest();
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}