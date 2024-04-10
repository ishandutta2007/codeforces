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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int query(const vector<int> &v) {
  const int k = v.size();
  cout << "? " << k;
  REP(i, k) cout << ' ' << v[i] + 1;
  cout << endl;
  int x; cin >> x;
  return x;
}

std::vector<int> centroid(const std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  std::vector<int> subtree(n, 1), res;
  std::function<void(int, int)> dfs = [&graph, n, &subtree, &res, &dfs](int par, int ver) {
    bool is_centroid = true;
    for (int e : graph[ver]) {
      if (e != par) {
        dfs(ver, e);
        subtree[ver] += subtree[e];
        is_centroid &= subtree[e] <= n / 2;
      }
    }
    if (is_centroid && (n - subtree[ver]) <= n / 2) res.emplace_back(ver);
  };
  dfs(-1, 0);
  std::sort(res.begin(), res.end());
  return res;
}

int main() {
  int n; cin >> n;
  vector<int> u(n - 1), v(n - 1); REP(i, n - 1) cin >> u[i] >> v[i], --u[i], --v[i];
  vector<vector<int>> graph(n);
  REP(i, n - 1) {
    graph[u[i]].emplace_back(v[i]);
    graph[v[i]].emplace_back(u[i]);
  }
  vector<int> map(n), exist(n, true);
  iota(ALL(map), 0);
  const int x = query(map);
  while (map.size() > 2) {
    const int cent = centroid(graph).front();
    auto f = [&](auto &&f, int par, int ver, vector<int> &vers) -> void {
      vers.emplace_back(ver);
      for (int e : graph[ver]) {
        if (e != par) f(f, ver, e, vers);
      }
    };
    vector<vector<int>> children;
    for (int e : graph[cent]) {
      children.emplace_back();
      f(f, cent, e, children.back());
    }
    const int l = children.size();
    assert(l >= 2);
    int s = 1;
    for (const vector<int> &child : children) s += child.size();
    vector dp(l + 1, vector(s + 1, 0));
    dp[0][0] = true;
    REP(i, l) REP(j, s + 1) {
      if (dp[i][j]) dp[i + 1][j] = dp[i + 1][j + children[i].size()] = true;
    }
    int j = (s - 1) / 2;
    while (j >= 0 && !dp[l][j]) --j;
    assert(j >= 0);
    vector<int> add(l, false), ver{map[cent]};
    for (int i = l - 1; i >= 0; --i) {
      if (!dp[i][j]) {
        assert(j >= children[i].size() && dp[i][j - children[i].size()]);
        add[i] = true;
        for (int e : children[i]) ver.emplace_back(map[e]);
        j -= children[i].size();
      }
    }
    assert(j == 0);
    if (query(ver) != x) {
      ver = {map[cent]};
      REP(i, l) {
        if (!add[i]) {
          for (int e : children[i]) ver.emplace_back(map[e]);
        }
      }
    }
    sort(ALL(ver));
    map.swap(ver);
    fill(ALL(exist), false);
    for (int e : map) exist[e] = true;
    graph.clear();
    graph.resize(map.size());
    REP(i, n - 1) {
      if (exist[u[i]] && exist[v[i]]) {
        int ui = lower_bound(ALL(map), u[i]) - map.begin();
        int vi = lower_bound(ALL(map), v[i]) - map.begin();
        graph[ui].emplace_back(vi);
        graph[vi].emplace_back(ui);
      }
    }
  }
  cout << "! " << map[0] + 1 << ' ' << map[1] + 1 << endl;
  return 0;
}