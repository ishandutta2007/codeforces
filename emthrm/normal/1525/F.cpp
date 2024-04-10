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

struct BipartiteMatching {
  std::vector<int> match;

  BipartiteMatching(int n) : n(n), graph(n), match(n, -1), used(n, -1), alive(n, true) {}

  void add_edge(int u, int v) {
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }

  int solve() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (alive[i] && match[i] == -1) {
        ++timestamp;
        if (dfs(i)) ++res;
      }
    }
    return res;
  }

  int push_back(int ver) {
    if (match[ver] != -1) match[match[ver]] = -1;
    match[ver] = -1;
    ++timestamp;
    dfs(ver);
    return match[ver];
  }

  void fix(int ver) {
    alive[ver] = false;
    if (match[ver] != -1) alive[match[ver]] = false;
  }

  int enable(int ver) {
    if (alive[ver]) return 0;
    alive[ver] = true;
    ++timestamp;
    return dfs(ver) ? 1 : 0;
  }

  int disable(int ver) {
    if (!alive[ver]) return 0;
    alive[ver] = false;
    if (match[ver] == -1) return 0;
    match[match[ver]] = -1;
    ++timestamp;
    int tmp = match[ver];
    match[ver] = -1;
    return dfs(tmp) ? 0 : -1;
  }

private:
  int n, timestamp = -1;
  std::vector<std::vector<int>> graph;
  std::vector<int> used;
  std::vector<bool> alive;

  bool dfs(int ver) {
    used[ver] = timestamp;
    for (int e : graph[ver]) {
      if (!alive[e]) continue;
      int tmp = match[e];
      if (tmp == -1 || (used[tmp] < timestamp && dfs(tmp))) {
        match[ver] = e;
        match[e] = ver;
        return true;
      }
    }
    return false;
  }
};

int main() {
  int n, m, k; cin >> n >> m >> k;
  BipartiteMatching matching(n * 2);
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    matching.add_edge(u, n + v);
  }
  int cover = n - matching.solve();
  vector<int> x(k), y(k); REP(i, k) cin >> x[i] >> y[i];
  ll point = -LINF, cur = 0;
  vector<int> ans;
  vector<vector<int>> strategy(k);
  vector<bool> pos_is_used(n, false), neg_is_used(n, false);
  using T = tuple<int, int, int>;
  priority_queue<T, vector<T>, greater<T>> que;
  REP(i, k) {
    ll tmp = cur;
    FOR(j, i + 1, k) tmp += x[j];
    if (tmp > point) {
      point = tmp;
      ans.clear();
      REP(j, i) {
        copy(ALL(strategy[j]), back_inserter(ans));
        ans.emplace_back(0);
      }
      REP(j, n) {
        if (!pos_is_used[j]) ans.emplace_back(j + 1);
        if (!neg_is_used[j]) ans.emplace_back(-(j + 1));
      }
      FOR(j, i, k) ans.emplace_back(0);
    }
    cur += x[i];
    que.emplace(y[i], x[i] / y[i], i);
    while (cover <= i + 1 && !que.empty()) {
      auto [cost, rem, id] = que.top(); que.pop();
      for (; rem > 0 && cover <= i + 1; --rem, ++cover) {
        bool ope = false;
        REP(j, n) {
          if (!pos_is_used[j]) {
            if (matching.disable(j) == -1) {
              strategy[id].emplace_back(j + 1);
              pos_is_used[j] = true;
              ope = true;
              break;
            }
            assert(matching.enable(j) == 0);
          }
        }
        if (!ope) {
          REP(j, n) {
            if (!neg_is_used[j]) {
              if (matching.disable(n + j) == -1) {
                strategy[id].emplace_back(-(j + 1));
                neg_is_used[j] = true;
                ope = true;
                break;
              }
              assert(matching.enable(n + j) == 0);
            }
          }
        }
        assert(ope);
        cur -= cost;
      }
      if (rem > 0) que.emplace(cost, rem, id);
    }
    if (cover <= i + 1) break;
  }
  if (cover > k && cur > point) {
    point = cur;
    ans.clear();
    REP(i, k) {
      copy(ALL(strategy[i]), back_inserter(ans));
      ans.emplace_back(0);
    }
  }
  int a = ans.size();
  // cerr << point << endl;
  cout << a << '\n';
  REP(i, a) cout << ans[i] << " \n"[i + 1 == a];
  return 0;
}