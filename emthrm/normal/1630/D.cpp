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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n); REP(i, n) cin >> a[i];
  int b = 0;
  while (m--) {
    int bi; cin >> bi;
    b = gcd(b, bi);
  }
  vector<vector<int>> group(b);
  REP(i, n) group[i % b].emplace_back(a[i]);
  ll s = 0;
  REP(i, b) {
    int neg = 0;
    for (int& e : group[i]) {
      if (e < 0) {
        neg ^= 1;
        e = -e;
      }
    }
    sort(ALL(group[i]));
    if (neg == 1) group[i].front() = -group[i].front();
    s += accumulate(ALL(group[i]), 0LL);
  }
  ll ans = s;
  REP(i, b) s -= group[i].front() * 2;
  chmax(ans, s);
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}