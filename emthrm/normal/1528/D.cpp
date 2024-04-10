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

constexpr int N = 600;
vector<pair<int, int>> graph[N]{};
ll ans[N][N]{};
int need[N]{};

int main() {
  REP(i, N) fill(ans[i], ans[i] + N, LINF);
  fill(need, need + N, INF);

  int n, m; cin >> n >> m;
  while (m--) {
    int a, b, c; cin >> a >> b >> c;
    graph[a].emplace_back(b, c);
  }
  REP(s, n) {
    ans[s][s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.emplace(0, s);
    while (!que.empty()) {
      auto [cost, ver] = que.top(); que.pop();
      if (cost > ans[s][ver]) continue;
      fill(need, need + n, INF);
      for (auto [b, c] : graph[ver]) need[(b + cost) % n] = c;
      int least = min_element(need, need + n) - need;
      for (int i = 1; i < n; ++i) {
        if (++least == n) least = 0;
        chmin(need[least], need[least == 0 ? n - 1 : least - 1] + 1);
      }
      REP(i, n) {
        if (ll nx = cost + need[i]; nx < ans[s][i]) {
          ans[s][i] = nx;
          que.emplace(nx, i);
        }
      }
    }
  }
  REP(i, n) REP(j, n) cout << ans[i][j] << " \n"[j + 1 == n];
  return 0;
}