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

void solve() {
  int n; cin >> n;
  --n;
  int lb = 0, ub = 32;
  while (ub - lb > 1) {
    int mid = (lb + ub) >> 1;
    ll tmp = 0;
    FOR(i, 1, mid + 1) tmp += 1LL << i;
    (tmp >= n ? ub : lb) = mid;
  }
  vector<int> ans(ub + 1, 0);
  ans[0] = 1;
  FOR(i, 1, ub) {
    ans[i] = 1 << i;
    n -= 1 << i;
  }
  assert(n > 0);
  ans[ub] = n;
  // REP(i, ub + 1) cout << ans[i] << " \n"[i == ub];
  if (ans[ub - 1] > ans[ub]) {
    assert(ub >= 2);
    int sum = ans[ub - 1] + ans[ub];
    ans[ub] = (sum + 1) / 2;
    ans[ub - 1] = sum / 2;
    assert(ans[ub - 1] * 2 >= ans[ub]);
  }
  FOR(i, 1, ub + 1) assert(ans[i - 1] <= ans[i]);
  cout << ub << '\n';
  FOR(i, 1, ub + 1) cout << ans[i] - ans[i - 1] << " \n"[i == ub];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}