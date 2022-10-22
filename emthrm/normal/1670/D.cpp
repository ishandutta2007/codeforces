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
  int lb = 0, ub = 12910;
  while (ub - lb > 1) {
    const int mid = (lb + ub) / 2;
    (mid * mid * 6 >= n ? ub : lb) = mid;
  }
  n -= (ub - 1) * (ub - 1) * 6;
  const int f = (ub - 1) * 4;
  if (n <= f) {
    cout << (ub - 1) * 3 + 1 << '\n';
  } else if (n <= f + (f + 2)) {
    cout << (ub - 1) * 3 + 2 << '\n';
  } else {
    cout << (ub - 1) * 3 + 3 << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}