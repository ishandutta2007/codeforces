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

using CostType = bool;
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

bool is_bipartite(const vector<vector<Edge>> &graph, vector<int> &color) {
  int n = graph.size();
  color.assign(n, 0);
  function<bool(int, int)> dfs = [&](int ver, int now) {
    color[ver] = now;
    for (const Edge &e : graph[ver]) {
      if (color[e.dst] == now || (color[e.dst] == 0 && !dfs(e.dst, -now))) return false;
    }
    return true;
  };
  REP(i, n) {
    if (color[i] == 0 && !dfs(i, 1)) return false;
  }
  return true;
}

int main() {
  int n; cin >> n;
  if (n % 2 == 0) {
    cout << "First\n";
    REP(i, n * 2) {
      cout << (i % n) + 1;
      if (i + 1 == n * 2) {
        cout << endl;
      } else {
        cout << ' ';
      }
    }
  } else {
    cout << "Second" << endl;
    int x = n * 2;
    vector<int> p(x), a(n, -1), b(n, -1);
    REP(i, x) {
      cin >> p[i]; --p[i];
      (a[p[i]] == -1 ? a[p[i]] : b[p[i]]) = i;
    }
    vector<vector<Edge>> graph(x);
    REP(i, n) {
      graph[i].emplace_back(i, i + n);
      graph[n + i].emplace_back(n + i, i);
    }
    REP(i, n) {
      graph[a[i]].emplace_back(a[i], b[i]);
      graph[b[i]].emplace_back(b[i], a[i]);
    }
    vector<int> col;
    assert(is_bipartite(graph, col));
    int sum = 0;
    REP(i, x) {
      if (col[i] == 1) (sum += i + 1) %= x;
    }
    vector<int> ans;
    if (sum == 0) {
      REP(i, x) {
        if (col[i] == 1) ans.emplace_back(i + 1);
      }
    } else {
      REP(i, x) {
        if (col[i] == -1) ans.emplace_back(i + 1);
      }
    }
    REP(i, n) {
      cout << ans[i];
      if (i + 1 == n) {
        cout << endl;
      } else {
        cout << ' ';
      }
    }
  }
  int single; cin >> single;
  assert(single == 0);
  return 0;
}