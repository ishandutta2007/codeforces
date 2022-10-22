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

int main() {
  constexpr int N = 3;
  vector<vector<ll>> a(N);
  REP(i, N) {
    int n; cin >> n;
    a[i].resize(n);
  }
  ll sum = 0;
  REP(i, N) {
    REP(j, a[i].size()) cin >> a[i][j];
    sort(ALL(a[i]));
    sum += accumulate(ALL(a[i]), 0LL);
  }
  ll ans = -LINF;
  REP(i, N) chmax(ans, sum - accumulate(ALL(a[i]), 0LL) * 2);
  REP(i, N) FOR(j, i + 1, N) chmax(ans, sum - (a[i][0] + a[j][0]) * 2);
  cout << ans << '\n';
  return 0;
}