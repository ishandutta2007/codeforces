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

class matching {
  public:
  vector< vector<int> > g;
  vector<int> pa;
  vector<int> pb;
  vector<int> was;
  int n, m;
  int res;
  int iter;
  matching(int _n, int _m) : n(_n), m(_m) {
    assert(0 <= n && 0 <= m);
    pa = vector<int>(n, -1);
    pb = vector<int>(m, -1);
    was = vector<int>(n, 0);
    g.resize(n);
    res = 0;
    iter = 0;
  }
  void add(int from, int to) {
    assert(0 <= from && from < n && 0 <= to && to < m);
    g[from].push_back(to);
  }
  bool dfs(int v) {
    was[v] = iter;
    for (int u : g[v]) {
      if (pb[u] == -1) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    for (int u : g[v]) {
      if (was[pb[u]] != iter && dfs(pb[u])) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    return false;
  }
  int solve() {
    while (true) {
      iter++;
      int add = 0;
      for (int i = 0; i < n; i++) {
        if (pa[i] == -1 && dfs(i)) {
          add++;
        }
      }
      if (add == 0) {
        break;
      }
      res += add;
    }
    return res;
  }
  int run_one(int v) {
    if (pa[v] != -1) {
      return 0;
    }
    iter++;
    return (int) dfs(v);
  }
};

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int d, n;
  cin >> d >> n;
  vector<int> a(n);
  for (auto& x : a) {
    string s;
    cin >> s;
    for (char ch : s) {
      x *= 2;
      x += ch - '0';
    }
  }
  matching graph(n, n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if ((a[i] & a[j]) == a[i]) {
        graph.add(i, j);
      }
    }
  }
  int tot = 0;
  vector<int> f(n);
  for (int i = 0; i < n; ++i) {
    f[i] = __builtin_popcount(a[i]) + 1;
    tot += f[i];
  }
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    return f[i] > f[j];
  });
  vector<bool> covered(n);
  int cost = 0;
  for (int v : ord) {
    if (graph.run_one(v)) {
      covered[v] = true;
      cost += f[v];
    }
  }
  cout << tot - cost - 1 << '\n';
  bool first = true;
  for (int i = 0; i < n; ++i) {
    if (!covered[i]) {
      if (!first) {
        cout << "R ";
      }
      first = false;
      vector<int> path;
      int cur = i;
      while (cur >= 0) {
        path.push_back(a[cur]);
        cur = graph.pb[cur];
      }
      reverse(path.begin(), path.end());
      cur = 0;
      for (int x : path) {
        for (int b = 0; b < d; ++b) {
          if ((x >> b & 1) > (cur >> b & 1)) {
            cout << (d - 1 - b) << ' ';
          }
        }
        cur = x;
      }
    }
  }
  cout << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}