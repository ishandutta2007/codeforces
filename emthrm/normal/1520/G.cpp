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
  int n, m, w; cin >> n >> m >> w;
  vector a(n, vector(m, 0)); REP(i, n) REP(j, m) cin >> a[i][j];
  vector<pair<int, int>> portal;
  REP(i, n) REP(j, m) {
    if (a[i][j] > 0) portal.emplace_back(i, j);
  }
  vector<ll> dist(n * m + 1, LINF);
  dist[0] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
  que.emplace(0, 0);
  while (!que.empty()) {
    auto [cost, ij] = que.top(); que.pop();
    if (cost > dist[ij]) continue;
    if (ij == n * m) {
      for (auto [y, x] : portal) {
        if (ll nx = dist[ij] + a[y][x]; nx < dist[y * m + x]) {
          dist[y * m + x] = nx;
          que.emplace(nx, y * m + x);
        }
      }
    } else {
      int i = ij / m, j = ij % m;
      REP(k, 4) {
        int y = i + dy[k], x = j + dx[k];
        if (0 <= y && y < n && 0 <= x && x < m && a[y][x] != -1 && dist[ij] + w < dist[y * m + x]) {
          dist[y * m + x] = dist[ij] + w;
          que.emplace(dist[ij] + w, y * m + x);
        }
      }
      if (a[i][j] > 0) {
        ll nx = dist[ij] + a[i][j];
        if (nx < dist[n * m]) {
          dist[n * m] = nx;
          que.emplace(nx, n * m);
        }
      }
    }
  }
  cout << (dist[n * m - 1] == LINF ? -1 : dist[n * m - 1]) << '\n';
  return 0;
}