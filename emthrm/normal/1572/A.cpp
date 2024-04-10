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
  int n; cin >> n;
  vector<vector<int>> graph(n);
  vector<int> k(n);
  REP(i, n) {
    cin >> k[i];
    REP(_, k[i]) {
      int a; cin >> a; --a;
      graph[a].emplace_back(i);
    }
  }
  int ans = 0;
  vector<int> is_read(n, false);
  priority_queue<int, vector<int>, greater<int>> que;
  REP(i, n) {
    if (k[i] == 0) {
      is_read[i] = true;
      que.emplace(i);
    }
  }
  for (; !que.empty(); ++ans) {
    priority_queue<int, vector<int>, greater<int>> nx;
    while (!que.empty()) {
      const int page = que.top(); que.pop();
      for (int e : graph[page]) {
        if (--k[e] == 0) {
          is_read[e] = true;
          (e < page ? nx : que).emplace(e);
        }
      }
    }
    que.swap(nx);
  }
  cout << (count(ALL(is_read), true) == n ? ans : -1) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}