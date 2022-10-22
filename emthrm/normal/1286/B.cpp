#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  vector<int> p(n), c(n);
  vector<vector<int> > graph(n);
  REP(i, n) {
    cin >> p[i] >> c[i]; --p[i];
    if (p[i] >= 0) graph[p[i]].emplace_back(i);
  }
  vector<int> subtree(n, 0);
  function<void(int)> dfs = [&](int ver) {
    for (int e : graph[ver]) {
      dfs(e);
      subtree[ver] += subtree[e] + 1;
    }
  };
  REP(i, n) {
    if (p[i] == -1) dfs(i);
  }
  REP(i, n) {
    if (subtree[i] < c[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  vector<int> cnt(n, 0), ans(n, -1), vers;
  int now = 1;
  function<void(int)> dfs2 = [&](int ver) {
    if (c[ver] == 0) {
      ans[ver] = now++;
      int pos = p[ver];
      while (pos >= 0) {
        ++cnt[pos];
        if (cnt[pos] == c[pos]) vers.emplace_back(pos);
        pos = p[pos];
      }
    }
    while (!vers.empty()) {
      int v = vers.back();
      ans[v] = now++;
      vers.pop_back();
      int pos = p[v];
      while (pos >= 0) {
        ++cnt[pos];
        if (cnt[pos] == c[pos]) vers.emplace_back(pos);
        pos = p[pos];
      }
    }
    for (int e : graph[ver]) dfs2(e);
  };
  REP(i, n) {
    if (p[i] == -1) dfs2(i);
  }
  cout << "YES\n";
  REP(i, n) cout << ans[i] << " \n"[i + 1 == n];
  return 0;
}