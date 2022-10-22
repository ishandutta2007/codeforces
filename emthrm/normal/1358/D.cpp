#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  int n; ll x; cin >> n >> x;
  vector<int> d(n); REP(i, n) cin >> d[i];
  REP(i, n) d.emplace_back(d[i]);
  vector<ll> sum(n * 2 + 1, 0), hug(n * 2 + 1, 0);
  REP(i, n * 2) sum[i + 1] = sum[i] + d[i];
  REP(i, n * 2) hug[i + 1] = hug[i] + 1LL * d[i] * (d[i] + 1) / 2;
  ll ans = 0;
  for (int i = n * 2 - 1; i >= n; --i) {
    int lb = 0, ub = i + 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      (sum[i + 1] - sum[mid] <= x ? ub : lb) = mid;
    }
    ll now = hug[i + 1] - hug[ub], rem = x - (sum[i + 1] - sum[ub]);
    now += 1LL * rem * ((d[ub - 1] - rem + 1) + d[ub - 1]) / 2;
    // cout << now << '\n';
    chmax(ans, now);
  }
  REP(i, n) {
    int lb = i, ub = n * 2 - 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      (sum[mid + 1] - sum[i + 1] + 1 <= x ? lb : ub) = mid;
    }
    ll now = hug[lb + 1] - hug[i + 1] + d[i], rem = x - 1 - (sum[lb + 1] - sum[i + 1]);
    now += 1LL * rem * (1 + rem) / 2;
    // cout << lb << ' ' << now << ' ' << hug[lb + 1] - hug[i + 1] << ' ' << rem << '\n';
    chmax(ans, now);
  }
  cout << ans << '\n';
  return 0;
}