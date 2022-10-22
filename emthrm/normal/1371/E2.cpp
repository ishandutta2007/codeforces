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
  int n, p; cin >> n >> p;
  vector<int> a(n); REP(i, n) cin >> a[i];
  sort(ALL(a));
  int small = a[n - 1];
  for (int i = n - 2; i >= 0; --i) small = max(small - 1, a[i]);
  int lb = small - 1, ub = 1000000000;
  while (ub - lb > 1) {
    int mid = (lb + ub) >> 1, j = 0;
    bool ok = true;
    REP(i, n) {
      while (j < n && a[j] <= mid + i) ++j;
      if (j <= i || (j - i) % p == 0) {
        ok = false;
        break;
      }
    }
    (ok ? lb : ub) = mid;
  }
  vector<int> ans;
  FOR(x, small, lb + 1) ans.emplace_back(x);
  int sz = ans.size();
  cout << sz << '\n';
  REP(i, sz) cout << ans[i] << " \n"[i + 1 == sz];
  return 0;
}