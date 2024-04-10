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
  int k; string n; cin >> k >> n;
  for (int d : vector<int>{1, 4, 6, 8, 9}) {
    if (count(ALL(n), '0' + d) > 0) {
      cout << 1 << '\n' << d << '\n';
      return;
    }
  }
  assert(k >= 2);
  REP(i, k) FOR(j, i + 1, k) {
    int ans = (n[i] - '0') * 10 + (n[j] - '0');
    if (ans != 23 && ans != 37 && ans != 53 && ans != 73) {
      cout << 2 << '\n' << ans << '\n';
      return;
    }
  }
  assert(false);
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}