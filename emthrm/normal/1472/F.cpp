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

void solve() {
  int n, m; cin >> n >> m;
  vector<int> r(m), c(m); REP(i, m) cin >> r[i] >> c[i], --r[i], --c[i];
  vector<int> x{0, n - 1};
  copy(ALL(c), back_inserter(x));
  sort(ALL(x));
  x.erase(unique(ALL(x)), x.end());
  // REP(i, x.size()) cout << x[i] << " \n"[i + 1 == x.size()];
  {
    vector<int> nx{0};
    FOR(i, 1, x.size()) {
      if ((x[i] - x[i - 1]) % 2 == 0) nx.emplace_back(x[i] - 1);
      nx.emplace_back(x[i]);
    }
    x.swap(nx);
  }
  n = x.size();
  vector block(2, vector(n, false));
  REP(i, m) {
    c[i] = lower_bound(ALL(x), c[i]) - x.begin();
    block[r[i]][c[i]] = true;
  }
  // REP(i, 2) {
  //   REP(j, n) cout << block[i][j];
  //   cout << '\n';
  // }
  REP(j, n) {
    if (!block[0][j] && !block[1][j]) {
      block[0][j] = block[1][j] = true;
    } else if (!block[0][j]) {
      if (j + 1 == n || block[0][j + 1]) {
        cout << "NO\n";
        return;
      }
      block[0][j] = block[0][j + 1] = true;
    } else if (!block[1][j]) {
      if (j + 1 == n || block[1][j + 1]) {
        cout << "NO\n";
        return;
      }
      block[1][j] = block[1][j + 1] = true;
    }
  }
  cout << "YES\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}