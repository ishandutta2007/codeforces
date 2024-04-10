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

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  ll x = 0;
  REP(i, n) x ^= a[i];
  if (x == 0) {
    cout << "YES\n";
    return;
  }
  if (k == 2) {
    cout << "NO\n";
    return;
  }
  int comp = 0;
  auto f = [&](auto &&f, int par, int ver) -> ll {
    ll y = a[ver];
    for (int e : graph[ver]) {
      if (e != par) y ^= f(f, ver, e);
    }
    if (y == x) {
      ++comp;
      y = 0;
    }
    return y;
  };
  for (int e : graph[0]) f(f, 0, e);
  cout << (comp >= 2 ? "YES\n" : "NO\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}