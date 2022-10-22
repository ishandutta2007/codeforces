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
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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

struct UnionFind {
  UnionFind(int n) : data(n, -1) {}

  int root(int ver) { return data[ver] < 0 ? ver : data[ver] = root(data[ver]); }

  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (data[u] > data[v]) swap(u, v);
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool same(int u, int v) { return root(u) == root(v); }

  int size(int ver) { return -data[root(ver)]; }

private:
  vector<int> data;
};

int main() {
  int n, k; string s; cin >> n >> k >> s;
  vector<vector<int> > x(n);
  REP(i, k) {
    int c; cin >> c;
    while (c--) {
      int xi; cin >> xi; --xi;
      x[xi].emplace_back(i);
    }
  }
  UnionFind uf(k * 2);
  vector<int> w(k * 2, 0);
  REP(i, k) w[i] = 1;
  int ans = 0;
  REP(lamp, n) {
    if (s[lamp] == '0') {
      if (x[lamp].size() == 1) {
        int u = x[lamp][0];
        ans -= min(w[uf.root(u)], w[uf.root(u + k)]);
        w[uf.root(u + k)] = INF;
        ans += w[uf.root(u)];
      } else if (x[lamp].size() == 2) {
        int u = x[lamp][0], v = x[lamp][1];
        if (!uf.same(u, v + k)) {
          ans -= min(w[uf.root(u)], w[uf.root(u + k)]);
          ans -= min(w[uf.root(v)], w[uf.root(v + k)]);
          int w1 = min(w[uf.root(u)] + w[uf.root(v + k)], INF), w2 = min(w[uf.root(v)] + w[uf.root(u + k)], INF);
          w[uf.root(u)] = w[uf.root(v + k)] = w[uf.root(v)] = w[uf.root(u + k)] = 0;
          uf.unite(u, v + k);
          uf.unite(v, u + k);
          w[uf.root(u)] = w1;
          w[uf.root(v)] = w2;
          ans += min(w1, w2);
        }
      }
    } else if (s[lamp] == '1') {
      if (x[lamp].size() == 1) {
        int u = x[lamp][0];
        ans -= min(w[uf.root(u)], w[uf.root(u + k)]);
        w[uf.root(u)] = INF;
        ans += w[uf.root(u + k)];
      } else if (x[lamp].size() == 2) {
        int u = x[lamp][0], v = x[lamp][1];
        if (!uf.same(u, v)) {
          ans -= min(w[uf.root(u)], w[uf.root(u + k)]);
          ans -= min(w[uf.root(v)], w[uf.root(v + k)]);
          int w1 = min(w[uf.root(u)] + w[uf.root(v)], INF), w2 = min(w[uf.root(u + k)] + w[uf.root(v + k)], INF);
          w[uf.root(u)] = w[uf.root(u + k)] = w[uf.root(v)] = w[uf.root(v + k)] = 0;
          uf.unite(u, v);
          uf.unite(u + k, v + k);
          w[uf.root(u)] = w1;
          w[uf.root(u + k)] = w2;
          ans += min(w1, w2);
        }
      }
    }
    // REP(i, k) cout << w[i] << ' ';
    // cout << '\n';
    // FOR(i, k, k * 2) cout << w[i] << ' ';
    // cout << '\n';
    cout << ans << '\n';
  }
  return 0;
}