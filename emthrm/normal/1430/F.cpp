#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n, k; cin >> n >> k;
  int tm = 0;
  map<pair<int, bool>, ll> dp{{{k, false}, 0}};
  while (n--) {
    int l, r, a; cin >> l >> r >> a;
    auto simulate = [&](int mag) -> pair<int, bool> {
      if (a <= mag) return {mag - a, l < r};
      int monster = a - mag, reload = (monster + k - 1) / k;
      if (reload > r - l) return {-1, false};
      return {1LL * k * reload - monster, l + reload < r};
    };
    map<pair<int, bool>, ll> nx;
    ll mn = LINF;
    for (auto [rem, sum] : dp) {
      if (tm < l || rem.second) chmin(mn, sum + rem.first);
      auto [last, reload] = simulate(rem.first);
      if (last == -1) continue;
      if (nx.count({last, reload}) == 0) nx[{last, reload}] = LINF;
      chmin(nx[{last, reload}], sum + a);
    }
    if (mn != LINF) {
      auto [last, reload] = simulate(k);
      if (last != -1) {
        if (nx.count({last, reload}) == 0) nx[{last, reload}] = LINF;
        chmin(nx[{last, reload}], mn + a);
      }
    }
    dp.swap(nx);
    if (dp.empty()) {
      cout << "-1\n";
      return 0;
    }
    tm = r;
  }
  ll ans = LINF;
  for (auto &p : dp) chmin(ans, p.second);
  cout << ans << '\n';
  return 0;
}