#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector group(1, vector(n, 0));
  iota(ALL(group[0]), 0);
  ll inv = 0;
  int x = 0;
  for (int b = 29; b >= 0; --b) {
    ll z = 0, o = 0;
    for (const vector<int> &g : group) {
      vector<int> bit(g.size());
      REP(i, g.size()) bit[i] = a[g[i]] >> b & 1;
      int cnt = 0;
      REP(i, g.size()) {
        if (bit[i] == 0) z += cnt;
        cnt += bit[i];
      }
      cnt = 0;
      REP(i, g.size()) {
        if (bit[i] == 1) o += cnt;
        cnt += bit[i] == 0;
      }
    }
    // cout << z << ' ' << o << '\n';
    int mask = (z <= o ? 0 : 1 << b);
    x |= mask;
    vector<vector<int>> nx;
    for (const vector<int> &g : group) {
      vector<int> bit(g.size());
      REP(i, g.size()) {
        a[g[i]] ^= mask;
        bit[i] = a[g[i]] >> b & 1;
      }
      int cnt = 0;
      REP(i, g.size()) {
        if (bit[i] == 0) inv += cnt;
        cnt += bit[i];
      }
      vector<int> zero, one;
      REP(i, g.size()) (a[g[i]] >> b & 1 ? one : zero).emplace_back(g[i]);
      if (!zero.empty()) nx.emplace_back(zero);
      if (!one.empty()) nx.emplace_back(one);
    }
    nx.swap(group);
  }
  cout << inv << ' ' << x << '\n';
  return 0;
}