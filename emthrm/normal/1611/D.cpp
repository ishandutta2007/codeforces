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
  int n; cin >> n;
  vector<int> b(n); REP(i, n) cin >> b[i], --b[i];
  vector<vector<int>> graph(n);
  int root = -1;
  REP(i, n) {
    if (b[i] == i) {
      root = i;
    } else {
      graph[b[i]].emplace_back(i);
    }
  }
  vector<int> p(n); REP(i, n) cin >> p[i], --p[i];
  vector<int> dist(n, 0), ans(n, 0);
  set<int> que{root};
  REP(i, n) {
    if (que.count(p[i]) == 0) {
      cout << "-1\n";
      return;
    }
    que.erase(p[i]);
    if (i > 0) ans[p[i]] = i - dist[b[p[i]]];
    dist[p[i]] = i;
    for (int e : graph[p[i]]) que.emplace(e);
  }
  REP(i, n) cout << ans[i] << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}