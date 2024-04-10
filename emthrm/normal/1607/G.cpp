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
  vector<int> a(n), b(n); REP(i, n) cin >> a[i] >> b[i];
  ll diff = 0;
  vector<int> lb(n), ub(n), is_odd(n, false);
  REP(i, n) {
    {
      int sub = min(b[i], m);
      lb[i] = (b[i] - sub) - (a[i] - (m - sub));
    }
    {
      int sub = min(a[i], m);
      ub[i] = (b[i] - (m - sub)) - (a[i] - sub);
    }
    if (ub[i] % 2 != 0) {
      is_odd[i] = true;
      --diff;
      ++ub[i]; ++lb[i];
    }
    ub[i] /= 2; lb[i] /= 2;
  }
  // cerr << diff << '\n';
  // REP(i, n) cerr << lb[i] << ' ' << ub[i] << '\n';
  ll l = accumulate(ALL(lb), 0LL), r = accumulate(ALL(ub), 0LL);
  ll target = [&]() -> ll {
    if (diff + 2 * l >= 0) return l;
    if (diff + 2 * r <= 0) return r;
    if (diff % 2 == 0) {
      assert(l <= -diff / 2 && -diff / 2 <= r);
      return -diff / 2;
    } else {
      assert(diff + 2 * l <= -1 && 1 <= diff + 2 * r);
      return (1 - diff) / 2;
    }
  } ();
  cout << abs(diff + target * 2) << '\n';
  ll s = 0;
  REP(i, n) {
    l -= lb[i];
    r -= ub[i];
    s += lb[i];
    ll add = lb[i], d = target - s;
    if (d > r) {
      assert(d - r <= ub[i] - lb[i]);
      s += d - r;
      add += d - r;
    }
    add *= 2;
    if (is_odd[i]) --add;
    ll x = (b[i] - a[i] + m - add) / 2;
    cout << m - x << ' ' << x << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}