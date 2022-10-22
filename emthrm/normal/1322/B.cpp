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
  vector<int> A(n); REP(i, n) cin >> A[i];
  int ans = 0;
  REP(bit, 25) {
    vector<int> a(n);
    REP(i, n) a[i] = A[i] % (1 << (bit + 1));
    // REP(i, n) cout << a[i] << " \n"[i + 1 == n];
    sort(ALL(a));
    int t = 1 << bit;
    ll cnt = 0;
    REP(i, n) {
      cnt += lower_bound(ALL(a), t * 2 - a[i]) - lower_bound(ALL(a), t - a[i]);
      cnt += lower_bound(ALL(a), t * 4 - a[i]) - lower_bound(ALL(a), t * 3 - a[i]);
      if ((a[i] + a[i]) >> bit & 1) --cnt;
    }
    cnt >>= 1;
    ans |= (cnt & 1) << bit;
  }
  cout << ans << '\n';
  return 0;
}