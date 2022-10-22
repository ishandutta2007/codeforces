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

void solve() {
  int n, m, k; cin >> n >> m >> k;
  vector<int> x(n), y(m);
  REP(i, n) cin >> x[i];
  REP(i, m) cin >> y[i];
  vector<vector<int>> hor(n - 1), ver(m - 1);
  while (k--) {
    int xp, yp; cin >> xp >> yp;
    const int x_idx = lower_bound(ALL(x), xp) - x.begin();
    if (x[x_idx] != xp) hor[x_idx - 1].emplace_back(yp);
    const int y_idx = lower_bound(ALL(y), yp) - y.begin();
    if (y[y_idx] != yp) ver[y_idx - 1].emplace_back(xp);
  }
  ll ans = 0;
  REP(i, n - 1) {
    const int l = hor[i].size();
    ans += l * (l - 1LL) / 2;
    map<int, int> mp;
    for (int yp : hor[i]) ++mp[yp];
    for (auto [_, num] : mp) ans -= num * (num - 1LL) / 2;
  }
  REP(i, m - 1) {
    const int l = ver[i].size();
    ans += l * (l - 1LL) / 2;
    map<int, int> mp;
    for (int xp : ver[i]) ++mp[xp];
    for (auto [_, num] : mp) ans -= num * (num - 1LL) / 2;
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}