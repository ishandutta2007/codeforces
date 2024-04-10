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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
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
  int f; cin >> f;
  vector<int> h(f); REP(i, f) cin >> h[i], --h[i];
  int k; cin >> k;
  vector<int> p(k); REP(i, k) cin >> p[i], --p[i];
  for (int i = k - 1; i >= 0; --i) {
    const int index = p[i];
    p[i] = h[index];
    h.erase(h.begin() + index);
  }
  vector<int> dist(n, -1);
  dist[0] = 0;
  vector can_reach(n, vector(1 << k, 0));
  can_reach[0][0] = true;
  queue<int> que({0});
  while (!que.empty()) {
    const int vertex = que.front(); que.pop();
    vector<int> cans;
    REP(i, 1 << k) {
      if (can_reach[vertex][i]) cans.emplace_back(i);
    }
    for (const int dst : graph[vertex]) {
      if (dist[dst] == -1 || dist[dst] == dist[vertex] + 1) {
        int bit = 0;
        REP(i, k) {
          if (p[i] == dst) bit |= 1 << i;
        }
        for (const int i : cans) can_reach[dst][i | bit] = true;
      }
      if (dist[dst] == -1) {
        dist[dst] = dist[vertex] + 1;
        que.emplace(dst);
      }
    }
  }
  vector<int> dp(1 << k, false);
  dp[0] = true;
  for (const int i : h) {
    vector<int> cans;
    REP(j, 1 << k) {
      if (can_reach[i][j]) cans.emplace_back(j);
    }
    for (int x = (1 << k) - 1; x >= 0; --x) {
      if (dp[x]) {
        for (const int j : cans) dp[x | j] = true;
      }
    }
  }
  int ans = k;
  REP(i, 1 << k) {
    if (dp[i]) chmin(ans, k - __builtin_popcount(i));
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}