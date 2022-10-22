#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

struct EulerianTrailInUndirectedGraph {
  std::vector<int> trail;

  EulerianTrailInUndirectedGraph(int n) : n(n), graph(n), visited(n) {}

  void add_edge(int u, int v) {
    graph[u].emplace_back(v, graph[v].size());
    graph[v].emplace_back(u, graph[u].size() - 1);
  }

  bool build(int s = -1) {
    trail.clear();
    int odd = 0, edges = 0;
    for (int i = 0; i < n; ++i) {
      if (graph[i].size() & 1) {
        ++odd;
        if (s == -1) s = i;
      }
      edges += graph[i].size();
    }
    if (s == -1) {
      for (int i = 0; i < n; ++i) {
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
    for (int i = 0; i < n; ++i) visited[i].assign(graph[i].size(), false);
    if (odd == 0 || (odd == 2 && (graph[s].size() & 1))) {
      dfs(s);
      if (trail.size() == (edges >> 1) + 1) {
        std::reverse(trail.begin(), trail.end());
        return true;
      }
      trail.clear();
    }
    return false;
  }

private:
  struct Edge {
    int dst, rev;
    Edge(int dst, int rev) : dst(dst), rev(rev) {}
  };

  int n;
  std::vector<std::vector<Edge>> graph;
  std::vector<std::vector<bool>> visited;

  void dfs(int ver) {
    int sz = graph[ver].size();
    for (int i = 0; i < sz; ++i) {
      if (!visited[ver][i]) {
        int nx = graph[ver][i].dst;
        visited[ver][i] = visited[nx][graph[ver][i].rev] = true;
        dfs(nx);
      }
    }
    trail.emplace_back(ver);
  }
};

int main() {
  int n, m; cin >> n >> m;
  set<pair<int, int>> edge;
  vector<vector<int>> graph(n);
  vector<int> deg(n, 0);
  while (m--) {
    int x, y; cin >> x >> y; --x; --y;
    edge.emplace(minmax(x, y));
    graph[x].emplace_back(y);
    graph[y].emplace_back(x);
    ++deg[x];
    ++deg[y];
  }
  auto f = [&](int c, const set<int> &era) -> void {
    EulerianTrailInUndirectedGraph et(n);
    for (auto [x, y] : edge) et.add_edge(x, y);
    if (!et.build(c)) return;
    vector<int> ans(et.trail.rbegin(), et.trail.rend());
    if (!era.empty()) {
      ans.emplace_back(-2);
      for (int e : era) {
        ans.emplace_back(e);
        ans.emplace_back(c);
      }
    }
    int k = ans.size();
    cout << k << '\n';
    REP(i, k) cout << ans[i] + 1 << " \n"[i + 1 == k];
    exit(0);
  };
  REP(c, n) {
    set<int> era;
    for (int e : graph[c]) {
      if (deg[e] & 1) {
        edge.erase(minmax(c, e));
        era.emplace(e);
      }
    }
    f(c, era);
    vector<int> list(ALL(era));
    for (int e : list) {
      edge.emplace(minmax(c, e));
      era.erase(e);
      f(c, era);
      era.emplace(e);
      edge.erase(minmax(c, e));
    }
    for (int e : list) edge.emplace(minmax(c, e));
  }
  cout << "0\n";
  return 0;
}