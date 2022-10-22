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

int main() {
  int n, k; cin >> n >> k;
  vector a(n, vector(k, 0)); REP(i, n) REP(j, k) cin >> a[i][j];
  set<vector<int>> s;
  REP(i, n) s.emplace(a[i]);
  ll ans = 0;
  REP(i, n) {
    int sets = 0;
    REP(j, n) {
      if (j == i) continue;
      vector<int> target(k);
      REP(x, k) target[x] = (a[i][x] == a[j][x] ? a[i][x] : a[i][x] ^ a[j][x] ^ 3);
      sets += s.count(target);
    }
    sets /= 2;
    ans += sets * (sets - 1) / 2;
  }
  cout << ans << '\n';
}