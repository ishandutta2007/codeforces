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

void solve() {
  int n, k; cin >> n >> k;
  map<pair<pair<int, int>, pair<int, int>>, int> a;
  REP(_, n) {
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2; --r1; --c1; --r2; --c2;
    REP(_, 2) {
      if (r1 == r2) {
        if (c1 > c2) swap(c1, c2);
        ++a[{{r1, c2}, {r1 + 1, c2}}];
      } else {
        if (r1 > r2) swap(r1, r2);
        ++a[{{r2, c1}, {r2, c1 + 1}}];
      }
      r1 = k - 1 - r1;
      c1 = k - 1 - c1;
      r2 = k - 1 - r2;
      c2 = k - 1 - c2;
    }
  }
  vector dist(k + 1, vector(k + 1, INF));
  dist[0][0] = 0;
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> que;
  que.emplace(dist[0][0], make_pair(0, 0));
  while (!que.empty()) {
    const auto [d, ij] = que.top(); que.pop();
    const auto [i, j] = ij;
    if (d > dist[i][j]) continue;
    REP(dir, 4) {
      const int y = i + DY4[dir], x = j + DX4[dir];
      if (0 <= y && y <= k && 0 <= x && x <= k) {
        pair<int, int> p = ij, q = make_pair(y, x);
        if (dir == 1 || dir == 2) swap(p, q);
        if (chmin(dist[y][x], dist[i][j] + (a.count({p, q}) ? a[{p, q}] : 0))) {
          que.emplace(dist[y][x], make_pair(y, x));
        }
      }
    }
  }
  cout << n - dist[k / 2][k / 2] << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}