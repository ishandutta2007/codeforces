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
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  int n, m, i, j; cin >> n >> m >> i >> j;
  vector<pair<int, int>> p{{1, 1}, {1, m}, {n, 1}, {n, m}};
  int x = 0, y = 1, ans = 0;
  REP(a, 4) REP(b, 4) {
    int u = i, d = i, l = j, r = j;
    chmin(u, min(p[a].first, p[b].first));
    chmax(d, max(p[a].first, p[b].first));
    chmin(l, min(p[a].second, p[b].second));
    chmax(r, max(p[a].second, p[b].second));
    if (chmax(ans, d - u + r - l)) {
      x = a;
      y = b;
    }
  }
  cout << p[x].first << ' ' << p[x].second << ' ' << p[y].first << ' ' << p[y].second << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}