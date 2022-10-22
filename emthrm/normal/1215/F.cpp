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

struct TwoSatLight {
  TwoSatLight(int n) : n(n), graph(n << 1), rev_graph(n << 1), used(n << 1, false), id(n << 1, -1) {}

  int negate(int x) { return (n + x) % (n << 1); }

  void add_or(int x, int y) {
    graph[negate(x)].emplace_back(y);
    graph[negate(y)].emplace_back(x);
    rev_graph[y].emplace_back(negate(x));
    rev_graph[x].emplace_back(negate(y));
  }

  void add_if(int x, int y) { add_or(negate(x), y); }

  void add_nand(int x, int y) { add_or(negate(x), negate(y)); }

  void set_true(int x) { add_or(x, x); }

  void set_false(int x) { set_true(negate(x)); }

  vector<bool> build() {
    REP(i, n << 1) {
      if (!used[i]) dfs(i);
    }
    int now = 0;
    for (int i = (n << 1) - 1; i >= 0; --i) {
      if (id[order[i]] == -1) rev_dfs(order[i], now++);
    }
    vector<bool> res(n);
    REP(i, n) {
      if (id[i] == id[negate(i)]) return {};
      res[i] = id[negate(i)] < id[i];
    }
    return res;
  }

private:
  int n;
  vector<vector<int> > graph, rev_graph;
  vector<bool> used;
  vector<int> id, order;

  void dfs(int ver) {
    used[ver] = true;
    for (int e : graph[ver]) {
      if (!used[e]) dfs(e);
    }
    order.emplace_back(ver);
  }

  void rev_dfs(int ver, int now) {
    id[ver] = now;
    for (int e : rev_graph[ver]) {
      if (id[e] == -1) rev_dfs(e, now);
    }
  }
};

int main() {
  int n, p, M, m; cin >> n >> p >> M >> m;
  TwoSatLight ts(p + M + 1);
  for (int i = M; i - 1 >= 0; --i) ts.add_if(p + i, p + i - 1);
  while (n--) {
    int x, y; cin >> x >> y; --x; --y;
    ts.add_or(x, y);
  }
  vector<int> l(p), r(p);
  REP(i, p) {
    cin >> l[i] >> r[i];
    ts.add_if(i, p + l[i]);
    if (r[i] < M) ts.add_if(i, ts.negate(p + r[i] + 1));
  }
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    ts.add_nand(u, v);
  }
  vector<bool> ans = ts.build();
  if (ans.empty()) {
    cout << "-1\n";
    return 0;
  }
  vector<int> stations;
  REP(i, p) {
    if (ans[i]) stations.emplace_back(i);
  }
  cout << stations.size() << ' ';
  for (int i = M; i >= 0; --i) {
    if (ans[p + i]) {
      cout << i << '\n';
      break;
    }
  }
  REP(i, stations.size()) cout << stations[i] + 1 << " \n"[i + 1 == stations.size()];
  return 0;
}