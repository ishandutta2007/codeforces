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

void solve() {
  int n, l; cin >> n >> l;
  vector<int> a(n); REP(i, n) cin >> a[i];
  a.emplace(a.begin(), 0);
  a.emplace_back(l);
  n += 2;
  vector<int> b(a);
  reverse(ALL(b));
  REP(i, n) b[i] = l - b[i];
  double lb = 0, ub = 1000000000;
  REP(_, 100) {
    double mid = (lb + ub) / 2;
    double le = 0, le_tm = mid, ri = 0, ri_tm = mid;
    FOR(i, 1, n) {
      int len = a[i] - a[i - 1];
      if (le_tm * i < len) {
        le += le_tm * i;
        break;
      }
      le_tm -= 1. * len / i;
      le = a[i];
    }
    FOR(i, 1, n) {
      int len = b[i] - b[i - 1];
      if (ri_tm * i < len) {
        ri += ri_tm * i;
        break;
      }
      ri_tm -= 1. * len / i;
      ri = b[i];
    }
    (le + ri >= l ? ub : lb) = mid;
  }
  cout << ub << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}