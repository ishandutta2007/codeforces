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

void solve() {
  int n, m, k; cin >> n >> m >> k;
  const int table = n / m, large = n % m;
  vector<int> b(n, 0), ord(n);
  iota(ALL(ord), 0);
  while (k--) {
    sort(ALL(ord), [&](int l, int r) -> bool { return b[l] < b[r]; });
    int idx = 0;
    REP(_, large) {
      cout << table + 1;
      REP(j, table + 1) {
        cout << ' ' << ord[idx] + 1;
        ++b[ord[idx++]];
      }
      cout << '\n';
    }
    REP(_, m - large) {
      cout << table;
      REP(j, table) cout << ' ' << ord[idx++] + 1;
      cout << '\n';
    }
  }
  assert(*max_element(ALL(b)) - *min_element(ALL(b)) <= 1);
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}