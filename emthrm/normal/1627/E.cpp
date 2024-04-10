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
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  vector<int> x(n); REP(i, n) cin >> x[i];
  vector<int> b(k), c(k), d(k), h(k);
  vector<vector<int>> ladder(n);
  REP(i, k) {
    int a; cin >> a >> b[i] >> c[i] >> d[i] >> h[i]; --a; --b[i]; --c[i]; --d[i];
    ladder[a].emplace_back(i);
  }
  vector<vector<pair<int, ll>>> tmp(n);
  tmp[0].emplace_back(0, 0);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
  REP(i, n) {
    if (tmp[i].empty()) continue;
    vector<int> col;
    for (const auto [j, _] : tmp[i]) col.emplace_back(j);
    for (int id : ladder[i]) col.emplace_back(b[id]);
    if (i + 1 == n) col.emplace_back(m - 1);
    sort(ALL(col));
    col.erase(unique(ALL(col)), col.end());
    const int l = col.size();
    vector<ll> dist(l, LINF);
    for (const auto [j, d] : tmp[i]) {
      chmin(dist[lower_bound(ALL(col), j) - col.begin()], d);
    }
    REP(j, l) {
      if (dist[j] != LINF) que.emplace(dist[j], j);
    }
    while (!que.empty()) {
      const auto [cost, j] = que.top(); que.pop();
      if (cost > dist[j]) continue;
      if (j > 0 && chmin(dist[j - 1], dist[j] + 1LL * (col[j] - col[j - 1]) * x[i])) {
        que.emplace(dist[j - 1], j - 1);
      }
      if (j + 1 < l && chmin(dist[j + 1], dist[j] + 1LL * (col[j + 1] - col[j]) * x[i])) {
        que.emplace(dist[j + 1], j + 1);
      }
    }
    if (i + 1 == n) {
      cout << dist[l - 1] << '\n';
      return;
    }
    for (int id : ladder[i]) {
      tmp[c[id]].emplace_back(d[id], dist[lower_bound(ALL(col), b[id]) - col.begin()] - h[id]);
    }
  }
  cout << "NO ESCAPE\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}