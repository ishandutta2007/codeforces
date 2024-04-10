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

#define int long long

void solve() {
  int n; cin >> n;
  vector<int> t(n), x(n); REP(i, n) cin >> t[i] >> x[i];
  int ans = 0, tm = 0, from = 0, to = 0;
  REP(i, n) {
    if (tm <= t[i]) {
      ans += i + 1 == n || abs(to - x[i]) <= t[i + 1] - t[i];
      tm = t[i] + abs(to - x[i]);
      from = to;
      to = x[i];
    } else {
      // ignore
      if (i + 1 == n || tm <= t[i + 1]) {
        if (from < to) {
          int l = max(from, to - (tm - t[i]));
          ans += l <= x[i] && x[i] <= to;
        } else {
          int r = min(from, to + (tm - t[i]));
          ans += to <= x[i] && x[i] <= r;
        }
      } else {
        if (from < to) {
          int l = max(from, to - (tm - t[i])), r = max(from, to - (tm - t[i + 1]));
          ans += l <= x[i] && x[i] <= r;
        } else {
          int l = min(from, to + (tm - t[i + 1])), r = min(from, to + (tm - t[i]));
          ans += l <= x[i] && x[i] <= r;
        }
      }
    }
  }
  cout << ans << '\n';
}

signed main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}