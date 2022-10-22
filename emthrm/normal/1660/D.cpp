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
  vector<int> a(n); REP(i, n) cin >> a[i];
  auto f = [&](int i, int j) -> int {
    bool sgn = true;
    int two = 0;
    FOR(k, i, j) {
      if (a[k] < 0) sgn = !sgn;
      if (abs(a[k]) == 2) ++two;
    }
    return sgn ? two : -two;
  };
  int x = n, y = 0, ans = 0;
  auto check = [&](int i, int j) -> void {
    if (chmax(ans, f(i, j))) {
      x = i;
      y = n - j;
    }
  };
  for (int i = 0; i < n;) {
    if (a[i] == 0) {
      ++i;
      continue;
    }
    int j = i + 1;
    while (j < n && a[j] != 0) ++j;
    check(i, j);
    for (int k = i; k < j; ++k) {
      if (a[k] < 0) {
        check(k + 1, j);
        break;
      }
    }
    for (int k = j - 1; k >= i; --k) {
      if (a[k] < 0) {
        check(i, k);
        break;
      }
    }
    i = j + 1;
  }
  cout << x << ' ' << y << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}