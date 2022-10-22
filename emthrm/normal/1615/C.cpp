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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; string a, b; cin >> n >> a >> b;
  int ans = INF;
  {
    int off = 0, on = 0;
    REP(i, n) {
      if (a[i] == '1' && b[i] == '0') ++off;
      if (a[i] == '0' && b[i] == '1') ++on;
    }
    if (on == off) chmin(ans, off + on);
  }
  REP(i, n) a[i] = (a[i] == '0' ? '1' : '0');
  {
    int off = 0, on = 0;
    REP(i, n) {
      if (a[i] == '1' && b[i] == '0') ++off;
      if (a[i] == '0' && b[i] == '1') ++on;
    }
    REP(i, n) {
      if (a[i] == '0') {
        if (b[i] == '1') --on;
        if (b[i] == '0') ++off;
        if (on == off) chmin(ans, off + on + 1);
        if (b[i] == '0') --off;
        if (b[i] == '1') ++on;
      }
    }
  }
  cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}