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

bool hillvalley(int a, int b, int c) {
  return (a < b && b > c) || (a > b && b < c);
}

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  int prev = 0;
  FOR(i, 1, n - 1) prev += hillvalley(a[i - 1], a[i], a[i + 1]);
  int ans = prev;
  REP(i, n) {
    if (i > 0) {
      int nxt = prev;
      for (int j = -2; j <= 2; ++j) {
        if (i + j - 1 >= 0 && i + j + 1 < n) nxt -= hillvalley(a[i + j - 1], a[i + j], a[i + j + 1]);
      }
      int tmp = a[i];
      a[i] = a[i - 1];
      for (int j = -2; j <= 2; ++j) {
        if (i + j - 1 >= 0 && i + j + 1 < n) nxt += hillvalley(a[i + j - 1], a[i + j], a[i + j + 1]);
      }
      a[i] = tmp;
      chmin(ans, nxt);
    }
    if (i + 1 < n) {
      int nxt = prev;
      for (int j = -2; j <= 2; ++j) {
        if (i + j - 1 >= 0 && i + j + 1 < n) nxt -= hillvalley(a[i + j - 1], a[i + j], a[i + j + 1]);
      }
      int tmp = a[i];
      a[i] = a[i + 1];
      for (int j = -2; j <= 2; ++j) {
        if (i + j - 1 >= 0 && i + j + 1 < n) nxt += hillvalley(a[i + j - 1], a[i + j], a[i + j + 1]);
      }
      a[i] = tmp;
      chmin(ans, nxt);
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}