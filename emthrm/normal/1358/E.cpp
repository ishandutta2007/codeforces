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
  int n; cin >> n;
  vector<int> a(n); REP(i, (n + 1) / 2) cin >> a[i];
  int x; cin >> x;
  FOR(i, (n + 1) / 2, n) a[i] = x;

  // sum[i] < sum[i + k] must holds
  vector<ll> sum(n + 1, 0);
  REP(i, n) sum[i + 1] = sum[i] + a[i];

  ll mx = 0;
  for (int k = n; k >= (n + 1) / 2; --k) {
    // sum[0] < sum[k]          sum[0] < sum[k]
    // sum[1] < sum[k + 1]      sum[1] - x < sum[k]
    // sum[2] < sum[k + 2]  ->  sum[2] - 2x < sum[k]
    // ...
    // sum[n - k] < sum[n]      sum[n - k] - (n - k)x < sum[k]
    chmax(mx, sum[n - k] - 1LL * x * (n - k));
    if (mx < sum[k]) {
      cout << k << '\n';
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}