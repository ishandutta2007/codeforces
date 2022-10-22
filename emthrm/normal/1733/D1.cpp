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

void solve() {
  int n, x, y; cin >> n >> x >> y;
  string s; cin >> s;
  REP(i, n) {
    char c; cin >> c;
    if (c == '1') s[i] = (s[i] == '0' ? '1' : '0');
  }
  vector<int> p;
  REP(i, n) {
    if (s[i] == '1') p.emplace_back(i);
  }
  if (p.size() % 2 == 1) {
    cout << "-1\n";
  } else if (p.empty()) {
    cout << 0 << '\n';
  } else if (p.size() == 2 && p.front() + 1 == p.back()) {
    ll ans = x;
    if (n == 4) {
      if (s[1] == '1' && s[2] == '1') {
        chmin(ans, y * 3LL);
      } else {
        chmin(ans, y * 2);
      }
    } else if (n >= 5) {
      chmin(ans, y * 2);
    }
    cout << ans << '\n';
  } else {
    cout << static_cast<ll>(p.size()) / 2 * y << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}