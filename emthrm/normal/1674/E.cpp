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

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  int ans = INF;
  FOR(i, 1, n) {
    int lb = 0, ub = a[i - 1] + a[i];
    while (ub - lb > 1) {
      const int mid = (lb + ub) / 2;
      (max(a[i - 1] - mid, 0) + max(a[i] - mid, 0) <= mid ? ub : lb) = mid;
    }
    chmin(ans, ub);
  }
  FOR(i, 2, n) {
    const int m = min(a[i - 2], a[i]);
    chmin(ans, (a[i - 2] - m + 1) / 2 + (a[i] - m + 1) / 2 + m);
    chmin(ans, (a[i - 2] - (m - 1) + 1) / 2 + (a[i] - (m - 1) + 1) / 2 + m - 1);
  }
  sort(ALL(a));
  chmin(ans, (a[0] + 1) / 2 + (a[1] + 1) / 2);
  cout << ans << '\n';
  return 0;
}