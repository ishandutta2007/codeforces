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
int popcount(int val) { return __builtin_popcount(val); }
int popcountll(ll val) { return __builtin_popcountll(val); }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int girth(const vector<vector<int> > &graph) {
  int n = graph.size(), res = INF;
  vector<int> dist(n);
  queue<int> que;
  REP(i, n) {
    fill(ALL(dist), INF);
    dist[i] = 0;
    que.emplace(i);
    while (!que.empty()) {
      int ver = que.front(); que.pop();
      for (int e : graph[ver]) {
        if (dist[e] == INF) {
          dist[e] = dist[ver] + 1;
          que.emplace(e);
        } else if (dist[e] >= dist[ver]) {
          chmin(res, dist[ver] + dist[e] + 1);
        }
      }
    }
  }
  return res;
}

int main() {
  int n; cin >> n;
  vector<ll> a;
  while (n--) {
    ll ai; cin >> ai;
    if (ai > 0) a.emplace_back(ai);
  }
  n = a.size();
  if (n == 0) {
    cout << "-1\n";
    return 0;
  }
  REP(bit, 60) {
    int cnt = 0;
    REP(i, n) cnt += a[i] >> bit & 1;
    if (cnt >= 3) {
      cout << "3\n";
      return 0;
    }
  }
  vector<vector<int> > graph(n);
  REP(i, n) REP(j, n) {
    if (i != j && a[i] & a[j]) graph[i].emplace_back(j);
  }
  int ans = girth(graph);
  cout << (ans == INF ? -1 : ans) << '\n';
  return 0;
}