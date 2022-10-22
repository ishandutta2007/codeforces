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

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  vector<int> path, depth(n, -1);
  function<bool(int)> dfs = [&](int ver) {
    if (depth[ver] >= (n + 1) / 2) return true;
    for (int e : graph[ver]) {
      if (depth[e] == -1) {
        depth[e] = depth[ver] + 1;
        path.emplace_back(e);
        if (dfs(e)) return true;
        path.pop_back();
      }
    }
    return false;
  };
  depth[0] = 1;
  dfs(0);
  if (!path.empty() || n <= 2) {
    reverse(ALL(path));
    path.emplace_back(0);
    int k = path.size();
    cout << "PATH\n" << k << '\n';
    REP(i, k) cout << path[i] + 1 << " \n"[i + 1 == k];
  } else {
    vector<vector<int>> d((n + 1) / 2);
    REP(i, n) d[depth[i]].emplace_back(i);
    vector<int> a, b;
    FOR(i, 1, (n + 1) / 2) {
      while (d[i].size() >= 2) {
        a.emplace_back(d[i].back());
        d[i].pop_back();
        b.emplace_back(d[i].back());
        d[i].pop_back();
      }
    }
    int k = a.size();
    cout << "PAIRING\n" << k << '\n';
    REP(i, k) cout << a[i] + 1 << ' ' << b[i] + 1 << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}