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

constexpr int N = 4;

void solve() {
  vector<ll> x(N), y(N); REP(i, N) cin >> x[i] >> y[i];
  ll ans = LINF;
  REP(i, N) FOR(j, i + 1, N) {
    int r = abs(x[j] - x[i]);
    REP(k, N) for (int d : vector<int>{-1, 1}) {
      vector<pair<int, int>> v{
        {x[i], y[k]}, {x[i], y[k] + d * r}, {x[j], y[k]}, {x[j], y[k] + d * r}
      };
      vector<int> dst(N);
      iota(ALL(dst), 0);
      do {
        ll dist = 0;
        REP(i, N) dist += abs(v[dst[i]].first - x[i]) + abs(v[dst[i]].second - y[i]);
        chmin(ans, dist);
      } while (next_permutation(ALL(dst)));
    }
  }
  REP(i, N) FOR(j, i + 1, N) {
    int r = abs(y[j] - y[i]);
    REP(k, N) for (int d : vector<int>{-1, 1}) {
      vector<pair<int, int>> v{
        {x[k], y[i]}, {x[k] + d * r, y[i]}, {x[k], y[j]}, {x[k] + d * r, y[j]}
      };
      vector<int> dst(N);
      iota(ALL(dst), 0);
      do {
        ll dist = 0;
        REP(i, N) dist += abs(v[dst[i]].first - x[i]) + abs(v[dst[i]].second - y[i]);
        chmin(ans, dist);
      } while (next_permutation(ALL(dst)));
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}