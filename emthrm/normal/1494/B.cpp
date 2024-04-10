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
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  int n, u, r, d, l; cin >> n >> u >> r >> d >> l;
  REP(i, 1 << 4) {
    int top = 0, right = 0, bottom = 0, left = 0;
    if (i & 1) {
      ++top;
      ++left;
    }
    if (i >> 1 & 1) {
      ++top;
      ++right;
    }
    if (i >> 2 & 1) {
      ++bottom;
      ++right;
    }
    if (i >> 3 & 1) {
      ++bottom;
      ++left;
    }
    if (top <= u && u - top <= n - 2
        && right <= r && r - right <= n - 2
        && bottom <= d && d - bottom <= n - 2
        && left <= l && l - left <= n - 2) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}