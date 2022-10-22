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

int main() {
  int n; cin >> n;
  vector<vector<pair<int, int> > > graph(n);
  REP(i, n - 1) {
    int x, y; cin >> x >> y; --x; --y;
    graph[x].emplace_back(y, i);
    graph[y].emplace_back(x, i);
  }
  int m; cin >> m;
  vector<int> a(m), b(m), g(m);
  REP(i, m) cin >> a[i] >> b[i] >> g[i], --a[i], --b[i];
  vector<int> idx(m);
  iota(ALL(idx), 0);
  sort(ALL(idx), [&](int l, int r) { return g[l] < g[r]; });
  vector<int> ans(n - 1, INF);
  REP(i, m) {
    int now = idx[i];
    vector<int> path;
    function<bool(int, int)> dfs = [&](int par, int ver) {
      if (ver == b[now]) return true;
      for (auto pr : graph[ver]) {
        if (pr.first != par) {
          path.emplace_back(pr.second);
          if (dfs(ver, pr.first)) return true;
          path.pop_back();
        }
      }
      return false;
    };
    dfs(-1, a[now]);
    for (int e : path) ans[e] = g[now];
  }
  REP(i, m) {
    vector<int> path;
    function<bool(int, int)> dfs = [&](int par, int ver) {
      if (ver == b[i]) return true;
      for (auto pr : graph[ver]) {
        if (pr.first != par) {
          path.emplace_back(pr.second);
          if (dfs(ver, pr.first)) return true;
          path.pop_back();
        }
      }
      return false;
    };
    dfs(-1, a[i]);
    int mn = INF;
    for (int e : path) chmin(mn, ans[e]);
    if (mn > g[i]) {
      cout << "-1\n";
      return 0;
    }
  }
  REP(i, n - 1) cout << (ans[i] == INF ? 1000000 : ans[i]) << " \n"[i + 1 == n - 1];
  return 0;
}