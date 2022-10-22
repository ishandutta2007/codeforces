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
  int n, m; cin >> n >> m;
  vector<ll> a(n); REP(i, n) cin >> a[i];
  FOR(i, 1, n) a[i] += a[i - 1];
  vector<ll> mx(a);
  FOR(i, 1, n) chmax(mx[i], mx[i - 1]);
  int idx = max_element(ALL(a)) - a.begin();
  if (a[n - 1] <= 0) {
    REP(q, m) {
      int x; cin >> x;
      if (a[idx] >= x) {
        int lb = -1, ub = n - 1;
        while (ub - lb > 1) {
          int mid = (lb + ub) >> 1;
          (mx[mid] >= x ? ub : lb) = mid;
        }
        cout << ub;
      } else {
        cout << "-1";
      }
      cout << " \n"[q + 1 == m];
    }
  } else {
    REP(q, m) {
      int x; cin >> x;
      ll ans = (max(x - a[idx], 0LL) + a[n - 1] - 1) / a[n - 1];
      x -= a[n - 1] * ans;
      ans *= n;
      int lb = -1, ub = n - 1;
      while (ub - lb > 1) {
        int mid = (lb + ub) >> 1;
        (mx[mid] >= x ? ub : lb) = mid;
      }
      ans += ub;
      cout << ans << " \n"[q + 1 == m];
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}