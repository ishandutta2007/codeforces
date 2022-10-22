#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n, a, b; cin >> n >> a >> b; --a; --b;
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  vector is_snake(n, false);
  vector<int> snakes{a};
  function<bool(int, int)> dfs = [&](int par, int ver) -> bool {
    if (ver == b) return true;
    for (int e : graph[ver]) {
      if (e != par) {
        is_snake[e] = true;
        snakes.emplace_back(e);
        if (dfs(ver, e)) return true;
        is_snake[e] = false;
        snakes.pop_back();
      }
    }
    return false;
  };
  is_snake[a] = true;
  dfs(-1, a);
  int snake_len = snakes.size();
  vector<vector<pair<int, int>>> child(n);
  function<int(int, int)> rec = [&](int par, int ver) -> int {
    int len = 1;
    for (int e : graph[ver]) {
      if (e == par) continue;
      int d = rec(ver, e);
      child[ver].emplace_back(d + 1, e);
      chmax(len, d + 1);
    }
    return len;
  };
  rec(-1, 0);
  vector three(n, false);
  function<void(int, int, int)> rec2 = [&](int par, int ver, int d) {
    if (d > 0) child[ver].emplace_back(d, par);
    sort(ALL(child[ver]), greater<pair<int, int>>());
    three[ver] = child[ver].size() >= 3 && child[ver][2].first >= snake_len;
    for (int e : graph[ver]) {
      if (e == par) continue;
      if (child[ver][0].second == e) {
        rec2(ver, e, child[ver].size() == 1 ? 2 : child[ver][1].first + 1);
      } else {
        rec2(ver, e, child[ver][0].first + 1);
      }
    }
  };
  rec2(-1, 0, 0);
  // REP(i, snake_len) cout << snakes[i] << " \n"[i + 1 == snake_len];
  // REP(i, n) cout << is_snake[i] << " \n"[i + 1 == n];
  // REP(i, n) cout << three[i] << " \n"[i + 1 == n];
  vector<int> rev(snakes);
  reverse(ALL(rev));
  int a_pos = -1, b_pos = -1, mx_a = 0, mx_b = 0;
  vector visited_a(n, false), visited_b(n, false);
  bool answer = false;
  while (a_pos < mx_a || b_pos < mx_b) {
    // cout << a_pos << ' ' << mx_a << "   ";
    while (a_pos < mx_a) {
      if (++a_pos >= snake_len) continue;
      answer |= three[snakes[a_pos]];
      function<void(int, int)> dfs2 = [&](int ver, int d) {
        for (int e : graph[ver]) {
          if (!visited_a[e] && !is_snake[e]) {
            visited_a[e] = true;
            answer |= three[e];
            chmax(mx_b, d + 1);
            dfs2(e, d + 1);
          }
        }
      };
      visited_a[snakes[a_pos]] = true;
      dfs2(snakes[a_pos], -a_pos);
    }
    // cout << b_pos << ' ' << mx_b << '\n';
    while (b_pos < mx_b) {
      if (++b_pos >= snake_len) continue;
      answer |= three[rev[b_pos]];
      function<void(int, int)> dfs2 = [&](int ver, int d) {
        for (int e : graph[ver]) {
          if (!visited_b[e] && !is_snake[e]) {
            visited_b[e] = true;
            answer |= three[e];
            chmax(mx_a, d + 1);
            dfs2(e, d + 1);
          }
        }
      };
      visited_b[rev[b_pos]] = true;
      dfs2(rev[b_pos], -b_pos);
    }
    if (answer) break;
  }
  cout << (answer ? "YES\n" : "NO\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}