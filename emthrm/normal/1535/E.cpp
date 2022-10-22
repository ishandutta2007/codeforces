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

constexpr int B = 19, N = 300000;
int a[N + 1]{}, c[N + 1]{}, depth[N + 1]{}, par[B][N + 1]{};

int main() {
  fill(depth, depth + (N + 1), -1);
  depth[0] = 0;
  REP(b, B) fill(par[b], par[b] + N, -1);
  auto f = [&](int v, int b) -> int {
    for (int i = 0; i < B && b > 0; ++i, b >>= 1) {
      if (b & 1) v = par[i][v];
    }
    return v;
  };

  int q; cin >> q >> a[0] >> c[0];
  for (int i = 1; i <= q; ++i) {
    int type; cin >> type;
    if (type == 1) {
      cin >> par[0][i] >> a[i] >> c[i];
      depth[i] = depth[par[0][i]] + 1;
      REP(b, B - 1) par[b + 1][i] = (par[b][i] == -1 ? -1 : par[b][par[b][i]]);
    } else if (type == 2) {
      int v, w; cin >> v >> w;
      if (a[v] == 0) {
        cout << 0 << ' ' << 0 << endl;
        continue;
      }
      int lb = 0, ub = depth[v] + 1;
      while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        (a[f(v, mid)] > 0 ? lb : ub) = mid;
      }
      int ton = 0;
      ll ans = 0;
      for (int j = lb; j >= 0 && ton < w; --j) {
        int ver = f(v, j), buy = min(a[ver], w - ton);
        a[ver] -= buy;
        ton += buy;
        ans += 1LL * buy * c[ver];
      }
      // REP(j, i) cout << a[j] << " \n"[j + 1 == i];
      cout << ton << ' ' << ans << endl;
    }
  }
  return 0;
}