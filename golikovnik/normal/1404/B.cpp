//  Copyright 2020 Nikita Golikov

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
  int n, a, b, da, db;
  cin >> n >> a >> b >> da >> db;
  --a, --b;
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  auto bfs = [&](int s, int who = -1) {
    vector<int> d(n, -1);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      auto v = q.front();
      q.pop();
      for (auto u : graph[v]) {
        if (d[u] < 0) {
          d[u] = d[v] + 1;
          q.push(u);
        }
      }
    }
    auto it = (int) (max_element(d.begin(), d.end()) - d.begin());
    if (who >= 0) {
      return make_pair(d[who], who);
    }
    return make_pair(d[it], it);
  };
  auto s = bfs(0);
  auto d = bfs(s.second).first;
  auto dst = bfs(a, b).first;
  smin(d, db);
  cout << (dst > da && 2 * da < d ? "Bob" : "Alice") << '\n';
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