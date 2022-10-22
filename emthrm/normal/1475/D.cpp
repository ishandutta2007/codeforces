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
  int n, m; cin >> n >> m;
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i], --b[i];
  vector<ll> mem[2];
  REP(i, n) mem[b[i]].emplace_back(a[i]);
  REP(i, 2) {
    sort(ALL(mem[i]), greater<ll>());
    mem[i].emplace(mem[i].begin(), 0);
    FOR(j, 1, mem[i].size()) mem[i][j] += mem[i][j - 1];
  }
  if (mem[0].back() + mem[1].back() < m) {
    cout << "-1\n";
    return;
  }
  ll ans = n * 2;
  REP(i, mem[0].size()) {
    int j = lower_bound(ALL(mem[1]), m - mem[0][i]) - mem[1].begin();
    if (j < mem[1].size()) chmin(ans, i + j * 2);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}