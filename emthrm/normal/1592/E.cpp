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

int main() {
  constexpr int B = 20;
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  int ans = 0;
  REP(_, B) {
    for (int i = 0; i < n;) {
      if ((a[i] & 1) == 0) {
        ++i;
        continue;
      }
      int j = i + 1;
      while (j < n && (a[j] & 1)) ++j;
      vector<int> b(j - i);
      REP(k, j - i) b[k] = a[i + k] >> 1;
      FOR(k, 1, j - i) b[k] ^= b[k - 1];
      map<int, int> m[2]{};
      REP(k, j - i) m[k & 1][b[k]] = k;
      REP(k, j - i) {
        const int x = (k == 0 ? 0 : b[k - 1]);
        if (m[(k & 1) ^ 1].count(x) == 1) chmax(ans, m[(k & 1) ^ 1][x] - k + 1);
      }
      i = j;
    }
    REP(i, n) a[i] >>= 1;
  }
  cout << ans << '\n';
  return 0;
}