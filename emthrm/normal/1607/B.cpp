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
  ll x0, n; cin >> x0 >> n;
  if (n == 0) {
    cout << x0 << '\n';
    return;
  }
  ll m = 0;
  if (x0 % 2 == 0) {
    x0 -= 1;
    m = (n - 1) / 4;
    x0 -= 4 * m;
  } else {
    x0 += 1;
    m = (n - 1) / 4;
    x0 += 4 * m;
  }
  m = m * 4 + 1;
  for (; m < n; ++m) {
    if (x0 % 2 == 0) {
      x0 -= m + 1;
    } else {
      x0 += m + 1;
    }
  }
  cout << x0 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}