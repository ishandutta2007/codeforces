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

pair<int, int> query(const vector<int> &cs) {
  int c = cs.size();
  cout << "? " << c << ' ';
  REP(i, c) {
    cout << cs[i] + 1;
    if (i + 1 == c) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  int x, d; cin >> x >> d;
  assert(x != -1 && d != -1);
  --x;
  return {x, d};
}

void solve() {
  int n; cin >> n;
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  vector<int> vers(n);
  iota(ALL(vers), 0);
  auto [root, dist] = query(vers);
  vector<bool> visited(n, false);
  visited[root] = true;
  vector<vector<int>> bfs{{root}};
  int rem = n - 1;
  while (rem > 0) {
    vector<int> nx;
    for (int e : bfs.back()) {
      for (int dst : graph[e]) {
        if (!visited[dst]) {
          visited[dst] = true;
          nx.emplace_back(dst);
          --rem;
        }
      }
    }
    bfs.emplace_back(nx);
  }
  int lb = dist / 2, ub = min(static_cast<int>(bfs.size()), dist + 1);
  vector<int> memo(bfs.size(), -1);
  while (ub - lb > 1) {
    int mid = (lb + ub) >> 1;
    int d;
    tie(memo[mid], d) = query(bfs[mid]);
    (d == dist ? lb : ub) = mid;
  }
  assert(lb >= 1);
  if (memo[lb] == -1) memo[lb] = query(bfs[lb]).first;
  root = memo[lb];
  fill(ALL(visited), false);
  visited[root] = true;
  bfs.clear();
  bfs.emplace_back(vector<int>{root});
  rem = n - 1;
  while (rem > 0) {
    vector<int> nx;
    for (int e : bfs.back()) {
      for (int dst : graph[e]) {
        if (!visited[dst]) {
          visited[dst] = true;
          nx.emplace_back(dst);
          --rem;
        }
      }
    }
    bfs.emplace_back(nx);
  }
  int ans = query(bfs[dist]).first;
  cout << "! " << root + 1 << ' ' << ans + 1 << endl;
  string s; cin >> s;
  while (s == "Incorrect");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}