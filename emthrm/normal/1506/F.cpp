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
  int n; cin >> n;
  vector<int> r(n), c(n);
  REP(i, n) cin >> r[i];
  REP(i, n) cin >> c[i];
  r.emplace_back(1);
  c.emplace_back(1);
  map<int, vector<int>> mp;
  REP(i, n + 1) {
    if (mp.count((r[i] - c[i]) / 2) == 0) mp[(r[i] - c[i]) / 2] = {};
    if ((r[i] - c[i]) % 2 == 0) mp[(r[i] - c[i]) / 2].emplace_back(r[i]);
  }
  ll ans = mp.rbegin()->first - mp.begin()->first;
  for (auto [_, v] : mp) {
    if (v.empty()) continue;
    sort(ALL(v));
    ans += v.back() - v.front();
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}