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

vector<int> topological_sort(const vector<vector<Edge>> &graph) {
  int n = graph.size();
  vector<int> deg(n, 0);
  REP(i, n) {
    for (const Edge &e : graph[i]) ++deg[e.dst];
  }
  queue<int> que;
  REP(i, n) {
    if (deg[i] == 0) que.emplace(i);
  }
  vector<int> res;
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    res.emplace_back(ver);
    for (const Edge &e : graph[ver]) {
      if (--deg[e.dst] == 0) que.emplace(e.dst);
    }
  }
  return res.size() == n ? res : vector<int>();
}

int main() {
  int n, m; cin >> n >> m;
  vector<vector<Edge>> graph(n);
  vector<vector<int>> rev(n);
  while (m--) {
    int j, k; cin >> j >> k; --j; --k;
    graph[j].emplace_back(j, k);
    rev[k].emplace_back(j);
  }
  vector<int> ts = topological_sort(graph);
  if (ts.empty()) {
    cout << "-1\n";
    return 0;
  }
  vector<int> mn1(n), mn2(n);
  iota(ALL(mn1), 0);
  iota(ALL(mn2), 0);
  for (int i = n - 1; i >= 0; --i) {
    for (const Edge &e : graph[ts[i]]) chmin(mn1[ts[i]], mn1[e.dst]);
  }
  REP(i, n) {
    for (int e : rev[ts[i]]) chmin(mn2[ts[i]], mn2[e]);
  }
  string ans = "";
  REP(i, n) ans += min(mn1[i], mn2[i]) < i ? 'E' : 'A';
  cout << count(ALL(ans), 'A') << '\n' << ans << '\n';
  return 0;
}