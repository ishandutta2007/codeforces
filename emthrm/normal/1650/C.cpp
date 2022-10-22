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
  vector<int> x(m), w(m); REP(i, m) cin >> x[i] >> w[i];
  vector<int> ord(m);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&](int a, int b) -> bool { return w[a] < w[b]; });
  int ans = 0;
  REP(i, n * 2) ans += w[ord[i]];
  vector<int> xs(n * 2);
  copy(ord.begin(), ord.begin() + (n * 2), xs.begin());
  sort(ALL(xs), [&](int a, int b) -> bool { return x[a] < x[b]; });
  cout << ans << '\n';
  REP(i, n) cout << xs[i] + 1 << ' ' << xs[n * 2 - 1 - i] + 1 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}