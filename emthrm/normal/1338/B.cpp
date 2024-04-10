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

int main() {
  int n; cin >> n;
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int a, b; cin >> a >> b; --a; --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  int root = 0;
  for (; root < n; ++root) {
    if (graph[root].size() > 1) break;
  }
  {
    bool one = true;
    function<int(int, int)> dfs = [&](int par, int ver) {
      int z = 0, o = 0;
      for (int e : graph[ver]) {
        if (e == par) continue;
        ++(dfs(ver, e) == 0 ? z : o);
      }
      if (z > 0 && o > 0) one = false;
      if (z == 0 && o == 0) return 0;
      return z > 0 ? 1 : 0;
    };
    dfs(-1, root);
    cout << (one ? "1 " : "3 ");
  }
  {
    int ans = 0;
    function<void(int, int)> dfs = [&](int par, int ver) {
      bool leaf = false;
      for (int e : graph[ver]) {
        if (e == par) continue;
        if (graph[e].size() == 1) {
          leaf = true;
        } else {
          ++ans;
          dfs(ver, e);
        }
      }
      ans += leaf;
    };
    dfs(-1, root);
    cout << ans << '\n';
  }
  return 0;
}