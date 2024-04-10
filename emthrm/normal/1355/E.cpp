#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n, a, r, m; cin >> n >> a >> r >> m;
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  vector<int> h(n); REP(i, n) cin >> h[i];
  sort(ALL(h));
  ll add = 0, remove = accumulate(ALL(h), 0LL) - 1LL * h[0] * n;
  ll ans = LINF;
  REP(i, n - 1) {
    // cout << add << ' ' << remove << '\n';
    chmin(ans, add * a + remove * r);
    chmin(ans, (add - min(add, remove)) * a + (remove - min(add, remove)) * r + min(add, remove) * m);
    if (h[i] == h[i + 1]) continue;
    {
      function<ll(ll)> calc = [&](ll height) {
        ll new_add = add + 1LL * (height - h[i]) * (i + 1);
        ll new_remove = remove - 1LL * (height - h[i]) * (n - 1 - i);
        return new_add * a + new_remove * r;
      };
      ll lb = h[i] + 1, ub = h[i + 1] + 1;
      while (ub - lb > 1) {
        ll mid = (lb + ub) >> 1;
        (calc(mid) - calc(mid - 1) <= 0 ? lb : ub) = mid;
      }
      chmin(ans, calc(lb));
    }
    {
      function<ll(ll)> calc = [&](ll height) {
        ll new_add = add + 1LL * (height - h[i]) * (i + 1);
        ll new_remove = remove - 1LL * (height - h[i]) * (n - 1 - i);
        // cout << '(' << height << ": " << new_add << ' ' << new_remove << ')';
        return (new_add - min(new_add, new_remove)) * a + (new_remove - min(new_add, new_remove)) * r + min(new_add, new_remove) * m;
      };
      ll lb = h[i] + 1, ub = h[i + 1] + 1;
      while (ub - lb > 1) {
        ll mid = (lb + ub) >> 1;
        // cout << mid << ": " << calc(mid) << ' ' << calc(mid - 1) << '\n';
        (calc(mid) - calc(mid - 1) <= 0 ? lb : ub) = mid;
      }
      chmin(ans, calc(lb));
    }
    add += 1LL * (h[i + 1] - h[i]) * (i + 1);
    remove -= 1LL * (h[i + 1] - h[i]) * (n - 1 - i);
  }
  assert(remove == 0);
  chmin(ans, add * a);
  cout << ans << '\n';
}