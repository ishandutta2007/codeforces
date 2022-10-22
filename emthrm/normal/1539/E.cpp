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
  int n, m; cin >> n >> m;
  n += 2;
  vector<int> k(n, 0), al(n, 0), bl(n, m), ar(n, 0), br(n, m); FOR(i, 2, n) cin >> k[i] >> al[i] >> bl[i] >> ar[i] >> br[i];
  vector<int> dpl(n, -1), dpr(n, -1);
  int lb_l = al[n - 1], ub_l = bl[n - 1], to_l = n, lb_r = ar[n - 1], ub_r = br[n - 1], to_r = n;
  bool takes_left = ar[n - 1] <= k[n - 1] && k[n - 1] <= br[n - 1], takes_right = al[n - 1] <= k[n - 1] && k[n - 1] <= bl[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    chmax(lb_l, al[i]);
    chmin(ub_l, bl[i]);
    chmax(lb_r, ar[i]);
    chmin(ub_r, br[i]);
    if (lb_l <= k[i] && k[i] <= ub_l && takes_left) dpl[i] = to_l;
    if (lb_r <= k[i] && k[i] <= ub_r && takes_right) dpr[i] = to_r;
    if (dpl[i] != -1) {
      lb_r = ar[i];
      ub_r = br[i];
      to_r = i;
      takes_right = true;
    }
    if (dpr[i] != -1) {
      lb_l = al[i];
      ub_l = bl[i];
      to_l = i;
      takes_left = true;
    }
    takes_left &= ar[i] <= k[i] && k[i] <= br[i];
    takes_right &= al[i] <= k[i] && k[i] <= bl[i];
  }
  if (dpl[0] == -1 && dpr[0] == -1) {
    cout << "No\n";
    return 0;
  }
  bool l = dpl[0] != -1;
  vector<int> ans(n, -1);
  for (int i = 0; i < n; l = !l) {
    if (l) {
      ans[i] = 0;
      int j = dpl[i++];
      for (; i < j; ++i) {
        ans[i] = 1;
      }
    } else {
      ans[i] = 1;
      int j = dpr[i++];
      for (; i < j; ++i) {
        ans[i] = 0;
      }
    }
  }
  cout << "Yes\n";
  FOR(i, 2, n) cout << ans[i] << " \n"[i + 1 == n];
  return 0;
}