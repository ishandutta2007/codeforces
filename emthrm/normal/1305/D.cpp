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

int query(int u, int v) {
  cout << "? " << u + 1 << ' ' << v + 1 << endl;
  int w; cin >> w;
  assert(w != -1);
  return w - 1;
}

void solve(int r) {
  cout << "! " << r + 1 << endl;
  exit(0);
}

int main() {
  int n; cin >> n;
  vector<set<int> > graph(n);
  REP(_, n - 1) {
    int x, y; cin >> x >> y; --x; --y;
    graph[x].emplace(y);
    graph[y].emplace(x);
  }
  set<int> ans;
  REP(i, n) ans.emplace(i);
  while (ans.size() > 1) {
    vector<int> leaves;
    for (int e : ans) {
      if (graph[e].size() == 1) leaves.emplace_back(e);
    }
    int u = leaves[0], v = leaves[1], w = query(u, v);
    if (w == u || w == v) solve(w);
    graph[*graph[u].begin()].erase(u);
    graph[*graph[v].begin()].erase(v);
    ans.erase(u);
    ans.erase(v);
  }
  solve(*ans.begin());
}