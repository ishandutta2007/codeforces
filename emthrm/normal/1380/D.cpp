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
  int n, m, x, k, y; cin >> n >> m >> x >> k >> y;
  vector<int> a(n), b(m);
  REP(i, n) cin >> a[i];
  a.emplace_back(INF);
  REP(i, m) cin >> b[i];
  b.emplace_back(INF);
  ++n;
  ++m;
  ll ans = 0;
  int l = -1;
  REP(i, m) {
    int r = l + 1;
    while (r < n && a[r] != b[i]) ++r;
    if (r == n) {
      cout << "-1\n";
      return 0;
    }
    int l_a = l == -1 ? INF : a[l];
    if (l + 1 < r) {
      bool is_small = false;
      if (l_a <= n) {
        is_small = true;
        FOR(j, l + 1, r) is_small &= a[j] < l_a;
      }
      if (!is_small && a[r] <= n) {
        is_small = true;
        FOR(j, l + 1, r) is_small &= a[j] < a[r];
      }
      int num = r - l - 1;
      if (num < k && !is_small) {
        cout << "-1\n";
        return 0;
      }
      if (!is_small) {
        num -= k;
        ans += x;
      }
      int b = num / k;
      ans += min(1LL * x, 1LL * k * y) * b;
      num -= b * k;
      ans += 1LL * num * y;
    }
    l = r;
  }
  cout << ans << '\n';
  return 0;
}