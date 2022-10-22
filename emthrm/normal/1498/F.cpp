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
  int n, k; cin >> n >> k;
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int x, y; cin >> x >> y; --x; --y;
    graph[x].emplace_back(y);
    graph[y].emplace_back(x);
  }
  vector child(n, vector(k * 2, 0LL));
  REP(i, n) cin >> child[i][0];
  auto f = [&](auto &&f, int par, int ver) -> void {
    for (int e : graph[ver]) {
      if (e != par) {
        f(f, ver, e);
        REP(i, k * 2) child[ver][(i + 1) % (k * 2)] ^= child[e][i];
      }
    }
  };
  f(f, -1, 0);
  // REP(i, n) REP(j, k * 2) cout << child[i][j] << " \n"[j + 1 == k * 2];
  auto g = [&](auto &&g, int par, int ver, const vector<ll> &v) -> void {
    REP(i, k * 2) child[ver][(i + 1) % (k * 2)] ^= v[i];
    for (int e : graph[ver]) {
      if (e != par) {
        vector<ll> tmp = child[ver];
        REP(i, k * 2) tmp[(i + 1) % (k * 2)] ^= child[e][i];
        g(g, ver, e, tmp);
      }
    }
  };
  g(g, -1, 0, vector<ll>(k * 2, 0));
  // REP(i, n) REP(j, k * 2) cout << child[i][j] << " \n"[j + 1 == k * 2];
  REP(ver, n) {
    ll x = 0;
    FOR(i, k, k * 2) x ^= child[ver][i];
    cout << (x != 0) << " \n"[ver + 1 == n];
  }
  return 0;
}