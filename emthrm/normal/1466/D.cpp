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
  vector<int> w(n); REP(i, n) cin >> w[i];
  vector<int> deg(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    ++deg[u];
    ++deg[v];
  }
  vector<int> a;
  REP(i, n) {
    REP(_, deg[i] - 1) a.emplace_back(w[i]);
  }
  assert(a.size() == n - 2);
  sort(ALL(a));
  ll ans = accumulate(ALL(w), 0LL);
  cout << ans;
  if (n == 2) {
    cout << '\n';
    return;
  }
  cout << ' ';
  FOR(i, 2, n) {
    ans += a.back();
    a.pop_back();
    cout << ans << " \n"[i + 1 == n];
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}