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

void solve() {
  int n; char c; string s; cin >> n >> c >> s;
  if (count(ALL(s), c) == n) {
    cout << 0 << '\n';
    return;
  }
  for (int x = n; x > 1; --x) {
    bool exist = false;
    for (int i = x; i <= n; i += x) {
      exist |= s[i - 1] != c;
    }
    if (!exist) {
      cout << 1 << '\n' << x << '\n';
      return;
    }
  }
  cout << 2 << '\n' << n << ' ';
  for (int i = n - 1; i > 1; --i) {
    if (n % i > 0) {
      cout << i << '\n';
      break;
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}