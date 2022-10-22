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
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
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
    int a, b; cin >> a >> b; --a; --b;
    graph[a].emplace_back(a, b, 1);
    graph[b].emplace_back(b, a, 1);
  }
  DoubleSweep ds(graph);
  ds.build_path();
  if (ds.diameter == n - 1) {
    cout << n - 1 << '\n' << ds.path.front() + 1 << ' ' << ds.path.back() + 1 << ' ' << ds.path[1] + 1 << '\n';
    return 0;
  }
  vector<bool> used(n, false);
  for (int e : ds.path) used[e] = true;
  function<pair<int, int>(int, int)> dfs = [&](int par, int ver) {
    if (graph[ver].size() == 1) return make_pair(0, ver);
    int mx = 0, idx = -1;
    for (const Edge &e : graph[ver]) {
      if (e.dst == par) continue;
      auto pr = dfs(ver, e.dst);
      ++pr.first;
      if (pr.first > mx) tie(mx, idx) = pr;
    }
    return make_pair(mx, idx);
  };
  int ans = 0, idx = -1;
  REP(i, n) {
    if (!used[i]) continue;
    for (const Edge &e : graph[i]) {
      if (used[e.dst]) continue;
      auto pr = dfs(i, e.dst);
      ++pr.first;
      if (pr.first > ans) tie(ans, idx) = pr;
    }
  }
  assert(idx != -1);
  cout << ds.diameter + ans << '\n';
  cout << ds.path.front() + 1 << ' ' << ds.path.back() + 1 << ' ' << idx + 1 << '\n';
  return 0;
}