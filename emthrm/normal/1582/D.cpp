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
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  for (int i = 0; i < n;) {
    if (i + 3 == n) {
      if (a[i + 1] + a[i + 2] != 0) {
        cout << a[i + 1] + a[i + 2] << ' ' << -a[i] << ' ' << -a[i] << '\n';
      } else if (a[i + 2] + a[i] != 0) {
        cout << -a[i + 1] << ' ' << a[i + 2] + a[i] << ' ' << -a[i + 1] << '\n';
      } else {
        assert(a[i] + a[i + 1] != 0);
        cout << -a[i + 2] << ' ' << -a[i + 2] << ' ' << a[i] + a[i + 1] << '\n';
      }
      i += 3;
    } else {
      cout << a[i + 1] << ' ' << -a[i] << " \n"[i + 2 == n];
      i += 2;
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}