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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
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
  vector a(n, vector(n, 0));
  REP(i, n) {
    cin >> a[i][i];
    FOR(j, 1, n) a[(i + j) % n][i] = (a[i][i] + j * i) % n;
  }
  // REP(r1, n) FOR(r2, r1 + 1, n) REP(c1, n) FOR(c2, c1 + 1, n) {
  //   assert((a[r1][c1] + a[r2][c2]) % n != (a[r1][c2] + a[r2][c1]) % n);
  // }
  REP(i, n) REP(j, n) cout << a[i][j] << " \n"[j + 1 == n];
  return 0;
}