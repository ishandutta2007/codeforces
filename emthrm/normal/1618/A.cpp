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

constexpr int N = 3, M = (1 << N) - 1;

void solve() {
  int b[M]; REP(i, M) cin >> b[i];
  for (int subset = (1 << N) - 1; subset < (1 << M);) {
    vector<int> a;
    REP(i, M) {
      if (subset >> i & 1) a.emplace_back(b[i]);
    }
    ll c[M]{};
    FOR(i, 1, 1 << N) {
      REP(j, N) {
        if (i >> j & 1) c[i - 1] += a[j];
      }
    }
    sort(c, c + M);
    bool is_same = true;
    REP(i, M) is_same &= b[i] == c[i];
    if (is_same) {
      REP(i, N) cout << a[i] << " \n"[i + 1 == N];
      return;
    }

    const int tmp1 = subset & -subset, tmp2 = subset + tmp1;
    subset = (((subset & ~tmp2) / tmp1) >> 1) | tmp2;
  }
  assert(false);
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}