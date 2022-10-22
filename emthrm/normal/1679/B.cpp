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
  int n, q; cin >> n >> q;
  vector<int> a(n), tm(n, -1);
  REP(i, n) cin >> a[i];
  int update = -2, t_x = 0;
  ll ans = accumulate(ALL(a), 0LL);
  REP(query, q) {
    int t; cin >> t;
    if (t == 1) {
      int i; cin >> i; --i;
      if (tm[i] < update) a[i] = t_x;
      ans -= a[i];
      cin >> a[i];
      tm[i] = query;
      ans += a[i];
    } else if (t == 2) {
      update = query;
      cin >> t_x;
      ans = 1LL * t_x * n;
    }
    cout << ans << '\n';
  }
  return 0;
}