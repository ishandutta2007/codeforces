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
  constexpr int B = 60;
  int n; cin >> n;
  vector<ll> a(n); REP(i, n) cin >> a[i];
  int cnt[B]{};
  const auto add = [&](const ll x) -> void {
    ++cnt[__builtin_popcountll(x)];
  };
  const auto rem = [&](const ll x) -> void {
    --cnt[__builtin_popcountll(x)];
  };
  vector<ll> mx(n), mn(n);
  const auto f = [&](auto&& f, int l, int r) -> ll {
    if (l + 1 == r) return 1;
    const int m = (l + r) / 2;
    ll ans = f(f, l, m) + f(f, m, r);
    copy(a.begin() + l, a.begin() + r, mx.begin() + l);
    for (int i = m - 2; i >= l; --i) chmax(mx[i], mx[i + 1]);
    FOR(i, m + 1, r) chmax(mx[i], mx[i - 1]);
    copy(a.begin() + l, a.begin() + r, mn.begin() + l);
    for (int i = m - 2; i >= l; --i) chmin(mn[i], mn[i + 1]);
    FOR(i, m + 1, r) chmin(mn[i], mn[i - 1]);
    {
      fill(cnt, cnt + B, 0);
      int r_min = r - 1, r_max = r - 1;
      FOR(i, l, m) {
        while (r_min >= m && mn[r_min] <= mn[i]) add(mn[r_min--]);
        while (r_max >= m && mx[r_max] > mx[i]) rem(mn[r_max--]);
        if (r_max < m) break;
        const int l_popcount = __builtin_popcountll(mx[i]);
        if (__builtin_popcountll(mn[i]) == l_popcount) ans += min(r_min, r_max) - (m - 1);
        if (r_max > r_min) ans += cnt[l_popcount];
      }
    }
    {
      fill(cnt, cnt + B, 0);
      int r_min = l, r_max = l;
      for (int i = r - 1; i >= m; --i) {
        while (r_max < m && mn[r_max] <= mn[i]) add(mn[r_max++]);
        while (r_min < m && mx[r_min] >= mx[i]) rem(mn[r_min++]);
        if (r_min >= m) break;
        const int l_popcount = __builtin_popcountll(mx[i]);
        if (__builtin_popcountll(mn[i]) == l_popcount) ans += m - max(r_min, r_max);
        if (r_min < r_max) ans += cnt[l_popcount];
      }
    }
    // cout << l << ' ' << r << ": " << ans << ' ';
    // int ans2 = 0;
    // FOR(i, l, r) {
    //   ll m = INF, M = 0;
    //   FOR(j, i, r) {
    //     chmin(m, a[j]);
    //     chmax(M, a[j]);
    //     ans2 += __builtin_popcountll(m) == __builtin_popcountll(M);
    //   }
    // }
    // cout << ans2 << '\n';
    return ans;
  };
  cout << f(f, 0, n) << '\n';
  return 0;
}