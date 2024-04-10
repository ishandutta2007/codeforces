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
  constexpr int B = 30;
  int n; cin >> n;
  vector<int> p(n), a(n);
  REP(i, n) cin >> p[i], --p[i];
  REP(i, n) cin >> a[i], --a[i];
  const int last = *max_element(ALL(a));
  if (last == n - 1) {
    REP(i, n) cout << a[i] + 1 << " \n"[i + 1 == n];
    return 0;
  }
  vector<int> is_root(n, true);
  REP(i, n) is_root[p[i]] = false;
  const int bye = count(ALL(is_root), true), turn = (last - (n - 1) + bye - 1) / bye;
  vector dp(B, vector(n, -1));
  REP(i, n) dp[0][i] = p[i];
  REP(i, B - 1) REP(j, n) dp[i + 1][j] = dp[i][dp[i][j]];
  vector<vector<int>> graph(n);
  REP(i, n) graph[p[i]].emplace_back(i);
  vector<int> is_visited(n, -1), ans(n, -1), sub(n, -1);
  REP(i, n) {
    if (is_visited[i] != -1) continue;
    int root = i;
    set<int> st;
    for (; !st.count(root); root = p[root]) {
      st.emplace(root);
    }
    is_visited[root] = 0;
    st = {root};
    int cycle_len = -1;
    queue<int> que({root});
    while (!que.empty()) {
      const int desk = que.front(); que.pop();
      for (int e : graph[desk]) {
        if (is_visited[e] == -1) {
          is_visited[e] = is_visited[desk] + 1;
          st.emplace(e);
          que.emplace(e);
        } else if (is_visited[e] == 0) {
          cycle_len = is_visited[desk] + 1;
        }
      }
    }
    map<int, vector<int>> m;
    for (int desk : st) {
      int cur = desk;
      REP(b, B) {
        if (turn >> b & 1) cur = dp[b][cur];
      }
      m[cur].emplace_back(desk);
    }
    for (const auto [desk, cands] : m) {
      ans[cands.front()] = a[desk];
      FOR(i, 1, cands.size()) sub[cands[i]] = a[desk];
    }
  }
  set<int> students;
  REP(i, n) students.emplace(i);
  REP(i, n) {
    if (a[i] < n) students.erase(a[i]);
  }
  REP(i, n) {
    if (sub[i] != -1) {
      const auto it = students.upper_bound(sub[i]);
      ans[i] = *it;
      students.erase(it);
    }
  }
  REP(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
  return 0;
}