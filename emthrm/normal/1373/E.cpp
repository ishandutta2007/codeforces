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
  int n, k; cin >> n >> k;
  if (k > n) {
    cout << "-1\n";
    return;
  }
  ll ans = LINF;
  if (n >= k * (k + 1) / 2 && (n - k * (k + 1) / 2) % (k + 1) == 0) {
    int base = (n - k * (k + 1) / 2) / (k + 1);
    string s = "";
    s += '0' + min(base, 9 - k);
    base -= min(base, 9 - k);
    while (base > 0) {
      s += '0' + min(base, 9);
      base -= min(base, 9);
    }
    reverse(ALL(s));
    chmin(ans, stoll(s));
  }
  int tmp2 = n - k * (k + 1) / 2;
  for (int i = 10 - k; i <= 9; ++i) {
    for (int d = 1; d <= 16; ++d) {
      int tmp = tmp2 + 9 * d * (i - (10 - k) + 1);
      if (tmp >= 0 && tmp % (k + 1) == 0) {
        int base = tmp / (k + 1);
        if (base >= i + (d - 1) * 9) {
          string s = "";
          s += '0' + i;
          base -= i;
          while (base > 0) {
            int sub = min(base, s.length() == d ? 8 : 9);
            s += '0' + sub;
            base -= sub;
          }
          reverse(ALL(s));
          chmin(ans, stoll(s));
        }
      }
    }
  }
  cout << (ans == LINF ? -1 : ans) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}