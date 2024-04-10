#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  vector<vector<int>> graph(n);
  FOR(i, 1, n) {
    int p; cin >> p; --p;
    graph[p].emplace_back(i);
  }
  vector<int> a(n); REP(i, n) cin >> a[i];
  function<tuple<ll, int, ll>(int)> dfs = [&](int ver) -> tuple<ll, int, ll> {
    if (graph[ver].empty()) return {a[ver], 1, a[ver]};
    ll mx = 0, sum = a[ver];
    int leaves = 0;
    for (int e : graph[ver]) {
      auto [p, q, r] = dfs(e);
      chmax(mx, p);
      leaves += q;
      sum += r;
    }
    return {max(mx, (sum + leaves - 1) / leaves), leaves, sum};
  };
  cout << get<0>(dfs(0)) << '\n';
  return 0;
}