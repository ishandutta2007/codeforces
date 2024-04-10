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
  vector<int> a(n); REP(i, n) cin >> a[i], --a[i];
  vector<vector<int>> graph(n);
  REP(i, n) graph[a[i]].emplace_back(i);
  vector<vector<int>> deg(n);
  REP(i, n) deg[graph[i].size()].emplace_back(i);
  int ans = 0;
  if (n >= 3 && deg[0].size() == 1 && deg[2].size() == 1) {
    if (deg[0].front() == graph[deg[2].front()].front()) {
      swap(graph[deg[2].front()][0], graph[deg[2].front()][1]);
    }
    a[graph[deg[2].front()].front()] = deg[0].front();
    ans = -1;
  }
  vector<int> given(n, false), b(n, -1);
  REP(i, n) {
    if (!given[a[i]]) {
      given[a[i]] = true;
      b[i] = a[i];
      ++ans;
    }
  }
  vector<pair<int, int>> rem;
  REP(i, n) {
    if (given[i]) continue;
    int ver = i;
    while (b[ver] != -1) ver = b[ver];
    rem.emplace_back(i, ver);
  }
  assert(rem.size() != 1);
  if (rem.size() >= 2) {
    FOR(i, 1, rem.size()) b[rem[i - 1].second] = rem[i].first;
    b[rem.back().second] = rem.front().first;
  }
  cout << ans << '\n';
  REP(i, n) cout << b[i] + 1 << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}