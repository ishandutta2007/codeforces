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
  int n; cin >> n;
  vector<int> x(n), t(n);
  REP(i, n) cin >> x[i];
  REP(i, n) cin >> t[i];
  const auto f = [&](const int tm) -> pair<int, int> {
    int l = 0, r = 100000000;
    REP(i, n) {
      chmax(l, x[i] - (tm - t[i]));
      chmin(r, x[i] + (tm - t[i]));
    }
    return {l, r};
  };
  int lb = *max_element(ALL(t)) - 1, ub = 200000000;
  while (ub - lb > 1) {
    const int mid = (lb + ub) / 2;
    const auto [l, r] = f(mid);
    (l > r ? lb : ub) = mid;
  }
  const auto [l, r] = f(ub);
  cout << (l + r) * 0.5 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}