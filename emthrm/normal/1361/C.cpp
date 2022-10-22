#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("avx2")

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

struct EulerianTrailInUndirectedGraph {
  struct Edge {
    int dst, rev, idx;
    Edge(int dst, int rev, int idx) : dst(dst), rev(rev), idx(idx) {}
  };

  vector<int> trail;

  EulerianTrailInUndirectedGraph(int n) : n(n), graph(n), visited(n) {}

  void add_edge(int u, int v, int idx) {
    graph[u].emplace_back(v, graph[v].size(), idx);
    graph[v].emplace_back(u, graph[u].size() - 1, -INF + idx);
  }

  bool build(int s = -1) {
    assert(!is_built);
    is_built = true;
    trail.clear();
    int odd = 0, edges = 0;
    REP(i, n) {
      if (graph[i].size() & 1) {
        ++odd;
        if (s == -1) s = i;
      }
      edges += graph[i].size();
    }
    if (s == -1) {
      REP(i, n) {
        if (!graph[i].empty()) {
          s = i;
          break;
        }
      }
      if (s == -1) {
        assert(edges == 0);
        trail.emplace_back(0);
        return true;
      }
    }
    REP(i, n) visited[i].assign(graph[i].size(), false);
    if (odd == 0) {
      dfs(s);
      // if (trail.size() == (edges >> 1) + 1) {
        reverse(ALL(trail));
        return true;
      // }
      trail.clear();
    }
    return false;
  }

private:
  bool is_built = false;
  int n;
  vector<vector<Edge>> graph;
  vector<vector<bool>> visited;

  void dfs(int ver) {
    while (!graph[ver].empty()) {
      int bk = graph[ver].size() - 1;
      if (visited[ver][bk]) {
        graph[ver].pop_back();
        continue;
      }
      int nx = graph[ver][bk].dst;
      visited[ver][bk] = visited[nx][graph[ver][bk].rev] = true;
      int idx = graph[ver][bk].idx;
      graph[ver].pop_back();
      dfs(nx);
      trail.emplace_back(idx);
    }
  }
};

bool solve(int n, vector<int> &a, vector<int> &b) {
  vector<int> comp(a);
  copy(ALL(b), back_inserter(comp));
  sort(ALL(comp));
  comp.erase(unique(ALL(comp)), comp.end());
  EulerianTrailInUndirectedGraph et(comp.size());
  REP(i, n) {
    a[i] = lower_bound(ALL(comp), a[i]) - comp.begin();
    b[i] = lower_bound(ALL(comp), b[i]) - comp.begin();
    et.add_edge(a[i], b[i], i);
  }
  return et.build() && et.trail.size() == n;
}

void solve_last(int n, vector<int> &a, vector<int> &b, vector<int> &ans) {
  vector<int> comp(a);
  copy(ALL(b), back_inserter(comp));
  sort(ALL(comp));
  comp.erase(unique(ALL(comp)), comp.end());
  EulerianTrailInUndirectedGraph et(comp.size());
  REP(i, n) {
    a[i] = lower_bound(ALL(comp), a[i]) - comp.begin();
    b[i] = lower_bound(ALL(comp), b[i]) - comp.begin();
    et.add_edge(a[i], b[i], i);
    // cout << a[i] << ' ' << b[i] << ' ' << i << '\n';
  }
  et.build();
  REP(i, n) {
    // cout << et.trail[i] << " \n"[i + 1 == n];
    if (et.trail[i] >= 0) {
      int idx = et.trail[i];
      ans.emplace_back(idx * 2);
      ans.emplace_back(idx * 2 + 1);
    } else {
      int idx = et.trail[i] + INF;
      ans.emplace_back(idx * 2 + 1);
      ans.emplace_back(idx * 2);
    }
  }
}

int main() {
  int n; cin >> n;
  vector<int> a(n), b(n); REP(i, n) cin >> a[i] >> b[i];
  int lb = 0, ub = 21;
  while (ub - lb > 1) {
    int k = (lb + ub) >> 1, mask = (1 << k) - 1;
    vector<int> c(n), d(n);
    REP(i, n) {
      c[i] = a[i] & mask;
      d[i] = b[i] & mask;
    }
    (!solve(n, c, d) ? ub : lb) = k;
  }
  int k = lb, mask = (1 << k) - 1;
  vector<int> c(n), d(n);
  REP(i, n) {
    c[i] = a[i] & mask;
    d[i] = b[i] & mask;
  }
  vector<int> ans;
  solve_last(n, c, d, ans);
  cout << k << '\n';
  REP(i, n * 2) cout << ans[i] + 1 << " \n"[i + 1 == n * 2];
  return 0;
}