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
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i], --a[i];
  vector<int> l(n, n), r(n, -1);
  REP(i, n) {
    chmin(l[a[i]], i);
    chmax(r[a[i]], i);
  }
  int ans = 0;
  for (int i = 0; i < n;) {
    if (l[a[i]] == r[a[i]]) {
      ++i;
      continue;
    }
    int zero = 2, right = r[a[i]];
    for (int x = i + 1; ;) {
      const int y = right;
      FOR(j, x, y) chmax(right, r[a[j]]);
      if (right == y) break;
      ++zero;
      x = y + 1;
    }
    ans += right - i + 1 - zero;
    i = right + 1;
  }
  cout << ans << '\n';
  return 0;
}