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

void solve() {
  int n; cin >> n;
  vector<int> p(n); REP(i, n) cin >> p[i];
  vector<int> pos(n);
  REP(i, n) pos[p[i]] = i;
  int l = pos[0], r = pos[0], mex = 1;
  set<int> s{0};
  ll ans = 0;
  REP(i, n) {
    if (i > 0 && l <= pos[i] && pos[i] <= r) continue;
    while (l > pos[i]) s.emplace(p[--l]);
    while (r < pos[i]) s.emplace(p[++r]);
    while (s.count(mex)) ++mex;
    const int len = r - l + 1;
    if (mex < (len + 1) / 2) continue;
    const int l_aff = l - (mex == n || r < pos[mex] ? 0 : pos[mex] + 1);
    const int r_aff = (mex == n || pos[mex] < l ? n - 1 : pos[mex] - 1) - r;
    int lb = len, ub = lb + l_aff + r_aff + 1;
    while (ub - lb > 1) {
      const int mid = (lb + ub) / 2;
      (mex >= (mid + 1) / 2 ? lb : ub) = mid;
    }
    if (l_aff < r_aff) {
      for (int i = 0; i <= l_aff && len + i <= lb; ++i) {
        ans += min(r_aff, lb - (len + i)) + 1;
      }
    } else {
      for (int i = 0; i <= r_aff && len + i <= lb; ++i) {
        ans += min(l_aff, lb - (len + i)) + 1;
      }
    }
    // cout << l << ' ' << r << ' ' << mex << ": " << ans << '\n';
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}