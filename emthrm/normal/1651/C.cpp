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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  auto f = [&](int i, int j) -> ll { return abs(a[i] - b[j]); };
  ll x = LINF, y = LINF, z = LINF, w = LINF;
  REP(i, n) chmin(x, f(0, i));
  REP(i, n) chmin(y, f(n - 1, i));
  REP(i, n) chmin(z, f(i, 0));
  REP(i, n) chmin(w, f(i, n - 1));
  cout << min({f(0, 0) + f(n - 1, n - 1),
               f(0, n - 1) + f(n - 1, 0),
               f(0, 0) + y + w,
               f(0, n - 1) + y + z,
               f(n - 1, 0) + x + w,
               f(n - 1, n - 1) + x + z,
               x + y + z + w})
       << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}