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
  int n; cin >> n;
  vector a(n, vector(n, 0)); REP(i, n) REP(j, n) cin >> a[i][j];
  vector b(n, vector(n, 0));
  int ans = 0;
  auto f = [&](int i, int j) -> void {
    ans ^= a[i][j];
    REP(k, 4) {
      const int y = i + DY[k], x = j + DX[k];
      if (0 <= y && y < n && 0 <= x && x < n) b[y][x] ^= 1;
    }
  };
  REP(j, n) f(0, j);
  FOR(i, 1, n) REP(j, n) {
    if (b[i - 1][j] == 0) f(i, j);
  }
  // REP(i, n) REP(j, n) assert(b[i][j] == 1);
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;

  constexpr int N = 4;
  int id[N][N]{};
  REP(i, N) {
    id[i][0] = (i == 0 ? 0 : id[i - 1][N - 1] + 1);
    FOR(j, 1, N) id[i][j] = id[i][j - 1] + 1;
  }
  bitset<N * N> a[N][N]{};
  REP(i, N) REP(j, N) REP(k, 4) {
    const int y = i + DY[k], x = j + DX[k];
    if (0 <= y && y < N && 0 <= x && x < N) a[i][j].set(id[y][x]);
  }
  REP(b, 1 << (N * N)) {
    bitset<N * N> sum = 0;
    REP(i, N * N) {
      if (b >> i & 1) {
        const int y = i / N, x = i % N;
        sum ^= a[y][x];
      }
    }
    if (sum.count() == N * N) {
      REP(i, N) {
        REP(j, N) cout << (b >> (i * N + j) & 1);
        cout << '\n';
      }
      cout << '\n';
    }
  }
}