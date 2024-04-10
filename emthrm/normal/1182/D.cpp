#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
int popcount(int val) { return __builtin_popcount(val); }
int popcountll(ll val) { return __builtin_popcountll(val); }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

using CostType = ll;
struct Edge {
  int src, dst; CostType cost;
  Edge(int src, int dst, CostType cost = 0) : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge &rhs) const {
    return cost != rhs.cost ? cost < rhs.cost : dst != rhs.dst ? dst < rhs.dst : src < rhs.src;
  }
  inline bool operator<=(const Edge &rhs) const { return !(rhs < *this); }
  inline bool operator>(const Edge &rhs) const { return rhs < *this; }
  inline bool operator>=(const Edge &rhs) const { return !(*this < rhs); }
};

struct DoubleSweep {
  using Pci = pair<CostType, int>;

  int s = -1, t;
  CostType diameter;
  vector<int> path;

  DoubleSweep(const vector<vector<Edge> > &graph) : graph(graph) {
    s = dfs1(-1, 0).second;
    tie(diameter, t) = dfs1(-1, s);
  }

  void build_path() {
    if (s != -1) {
      path.emplace_back(s);
      dfs2(-1, s);
    }
  }

private:
  const vector<vector<Edge> > graph;

  Pci dfs1(int par, int ver) {
    Pci res = {0, ver};
    for (const Edge &e : graph[ver]) {
      if (e.dst != par) {
        Pci pr = dfs1(ver, e.dst);
        pr.first += e.cost;
        if (pr.first > res.first) res = pr;
      }
    }
    return res;
  }

  bool dfs2(int par, int ver) {
    if (ver == t) return true;
    for (const Edge &e : graph[ver]) {
      if (e.dst != par) {
        path.emplace_back(e.dst);
        if (dfs2(ver, e.dst)) return true;
        path.pop_back();
      }
    }
    return false;
  }
};

int main() {
  int n; cin >> n;
  vector<vector<Edge> > graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(u, v, 1);
    graph[v].emplace_back(v, u, 1);
  }
  DoubleSweep ds(graph);
  function<void(int)> check = [&](int root) {
    vector<bool> visited(n, false);
    visited[root] = true;
    queue<int> que;
    que.emplace(root);
    bool ok = true;
    while (!que.empty()) {
      vector<int> ver;
      while (!que.empty()) {
        ver.emplace_back(que.front()); que.pop();
      }
      set<int> deg;
      for (int v : ver) {
        for (const Edge &e : graph[v]) {
          if (!visited[e.dst]) {
            visited[e.dst] = true;
            que.emplace(e.dst);
            deg.emplace(graph[e.dst].size());
          }
        }
      }
      if (deg.size() > 1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << root + 1 << '\n';
      exit(0);
    }
  };
  check(ds.s);
  check(ds.t);
  if (ds.diameter & 1) {
    cout << "-1\n";
    return 0;
  }
  ds.build_path();
  vector<int> deg;
  for (int i = ds.diameter / 2 - 1; i >= 0; --i) {
    deg.emplace_back(graph[ds.path[i]].size());
  }
  int root = ds.path[ds.diameter / 2];
  vector<bool> visited(n, false);
  visited[root] = true;
  queue<int> que;
  que.emplace(root);
  int ans;
  function<void(int)> dfs = [&](int ver) {
    if (graph[ver].size() == 1) {
      ans = ver;
    } else {
      for (Edge e : graph[ver]) {
        if (!visited[e.dst]) {
          visited[e.dst] = true;
          dfs(e.dst);
          break;
        }
      }
    }
  };
  int idx = 0;
  while (!que.empty()) {
    vector<int> same_depth;
    while (!que.empty()) {
      same_depth.emplace_back(que.front()); que.pop();
    }
    for (int v : same_depth) {
      for (const Edge &e : graph[v]) {
        if (!visited[e.dst]) {
          visited[e.dst] = true;
          que.emplace(e.dst);
          if (deg[idx] != graph[e.dst].size()) {
            dfs(e.dst);
            check(ans);
            cout << "-1\n";
            return 0;
          }
        }
      }
    }
    ++idx;
  }
  cout << root + 1 << '\n';
  return 0;
}