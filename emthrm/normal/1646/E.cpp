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

int main() {
  constexpr int K = 19, M = 1000000;
  int n, m; cin >> n >> m;
  int num[K + 1]{};
  bool is_written[K * M + 1]{};
  FOR(k, 1, K + 1) {
    num[k] = num[k - 1];
    FOR(j, 1, m + 1) {
      if (!is_written[k * j]) {
        is_written[k * j] = true;
        ++num[k];
      }
    }
  }
  ll ans = 1;
  vector<int> is_visited(n + 1, false);
  FOR(i, 2, n + 1) {
    if (is_visited[i]) continue;
    int k = 0;
    for (ll j = i; j <= n; j *= i) {
      ++k;
      is_visited[j] = true;
    }
    ans += num[k];
  }
  cout << ans << '\n';
  return 0;
}