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
  int n, m; cin >> n >> m;
  vector<__int128> s(n, 0);
  REP(i, n) {
    vector<ll> c(m); REP(i, m) cin >> c[i];
    FOR(i, 1, m) c[i] += c[i - 1];
    s[i] = accumulate(ALL(c), static_cast<__int128>(0));
  }
  if (s.front() == s.back()) {
    FOR(i, 1, n - 1) {
      if (s[i] != s.front()) {
        cout << i + 1 << ' ' << static_cast<ll>(s.front() - s[i]) << '\n';
        break;
      }
    }
  } else if (s[1] == s.front()) {
    cout << n << ' ' << static_cast<ll>(s.front() - s[n - 1]) << '\n';
  } else {
    assert(s[1] == s.back());
    cout << 1 << ' ' << static_cast<ll>(s.back() - s.front()) << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}