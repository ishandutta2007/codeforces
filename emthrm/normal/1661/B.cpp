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

int main() {
  constexpr int A = 32768;
  vector<int> graph[A]{};
  REP(i, A) {
    graph[(i + 1) % A].emplace_back(i);
    graph[i * 2 % A].emplace_back(i);
  }
  int ans[A]{};
  fill(ans, ans + A, -1);
  ans[0] = 0;
  queue<int> que({0});
  while (!que.empty()) {
    const int v = que.front(); que.pop();
    for (const int e : graph[v]) {
      if (ans[e] == -1) {
        ans[e] = ans[v] + 1;
        que.emplace(e);
      }
    }
  }

  int n; cin >> n;
  REP(i, n) {
    int a; cin >> a;
    cout << ans[a] << " \n"[i + 1 == n];
  }
  return 0;
}