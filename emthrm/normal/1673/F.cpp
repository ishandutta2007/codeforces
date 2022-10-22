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
  constexpr int B = 5;
  int n, k; cin >> n >> k;
  vector a(n, vector(n, 0));
  REP(i, n) {
    int v = i ^ (i >> 1);
    for (int b = B - 1; b > 0; --b) {
      v ^= (v >> b & 1) << (b * 2);
      if (v >> b & 1) v ^= 1 << b;
    }
    fill(ALL(a[i]), v);
  }
  REP(j, n) {
    int v = j ^ (j >> 1);
    for (int b = B - 1; b >= 0; --b) {
      v ^= (v >> b & 1) << (b * 2 + 1);
      if (v >> b & 1) v ^= 1 << b;
    }
    REP(i, n) a[i][j] ^= v;
  }
  REP(i, n) FOR(j, 1, n) cout << (a[i][j] ^ a[i][j - 1]) << " \n"[j + 1 == n];
  FOR(i, 1, n) REP(j, n) cout << (a[i][j] ^ a[i - 1][j]) << " \n"[j + 1 == n];
  cout << endl;
  int y = 0, x = 0;
  while (k--) {
    int d; cin >> d;
    REP(i, n) REP(j, n) {
      if ((a[i][j] ^ a[y][x]) == d) {
        y = i;
        x = j;
        goto never_use;
      }
    }
never_use:
    cout << y + 1 << ' ' << x + 1 << endl;
  }
  return 0;
}