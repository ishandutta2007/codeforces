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

using CostType = int;
struct Edge {
  int src, dst; CostType cost;
  Edge(int src, int dst, CostType cost = 0) : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge &x) const {
    return cost != x.cost ? cost < x.cost : dst != x.dst ? dst < x.dst : src < x.src;
  }
  inline bool operator<=(const Edge &x) const { return !(x < *this); }
  inline bool operator>(const Edge &x) const { return x < *this; }
  inline bool operator>=(const Edge &x) const { return !(*this < x); }
};

struct DoubleSweep {
  using Pci = pair<CostType, int>;

  int s = -1, t;
  CostType diameter;
  vector<int> path;

  DoubleSweep(const vector<vector<Edge>> &graph) : graph(graph) {
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
  const vector<vector<Edge>> graph;

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

void solve() {
  int n, a, b, da, db; cin >> n >> a >> b >> da >> db; --a; --b;
  vector<vector<Edge>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(u, v, 1);
    graph[v].emplace_back(v, u, 1);
  }
  if (db <= da * 2) {
    cout << "Alice\n";
    return;
  }
  int d = -1;
  function<bool(int, int, int)> dfs = [&](int par, int ver, int dist) {
    if (ver == b) {
      d = dist;
      return true;
    }
    for (const Edge &e : graph[ver]) {
      if (e.dst != par && dfs(ver, e.dst, dist + 1)) return true;
    }
    return false;
  };
  dfs(-1, a, 0);
  assert(d != -1);
  if (d <= da) {
    cout << "Alice\n";
    return;
  }
  DoubleSweep ds(graph);
  cout << (ds.diameter <= da * 2 ? "Alice\n" : "Bob\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}