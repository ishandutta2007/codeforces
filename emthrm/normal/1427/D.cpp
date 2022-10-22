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
  vector<int> c(n); REP(i, n) cin >> c[i];
  if (is_sorted(ALL(c))) {
    cout << 0 << '\n';
    return 0;
  }
  vector<vector<int>> d;
  bool fr = c[0] == 1;
  FOR(cur, 1, n) {
    vector<int> ds;
    if (fr) {
      if (c[cur - 1] == cur) continue;
      REP(i, cur - 1) ds.emplace_back(1);
      int pos = cur - 1;
      while (pos < n && c[pos] != cur) ++pos;
      ds.emplace_back(pos - (cur - 1) + 1);
      if (pos < n - 1) ds.emplace_back(n - pos - 1);
    } else {
      if (c[n - cur] == cur) continue;
      int pos = 0;
      while (pos < n && c[pos] != cur) ++pos;
      if (pos > 0) ds.emplace_back(pos);
      ds.emplace_back(n - pos - (cur - 1));
      REP(_, cur - 1) ds.emplace_back(1);
    }
    d.emplace_back(ds);
    vector<int> nx;
    int k = ds.size();
    vector<vector<int>> tmp(k);
    reverse(ALL(c));
    REP(i, k) {
      int di = ds[i];
      REP(_, di) {
        tmp[i].emplace_back(c.back());
        c.pop_back();
      }
    }
    for (int i = k - 1; i >= 0; --i) for (int e : tmp[i]) nx.emplace_back(e);
    c.swap(nx);
    // REP(i, n) cout << c[i] << " \n"[i + 1 == n];
    fr = !fr;
  }
  if (!fr) {
    d.emplace_back();
    REP(i, n) d.back().emplace_back(1);
  }
  int q = d.size();
  assert(q <= n);
  cout << q << '\n';
  REP(i, q) {
    assert(accumulate(ALL(d[i]), 0) == n);
    int k = d[i].size();
    assert(k > 1);
    cout << k << ' ';
    REP(j, k) cout << d[i][j] << " \n"[j + 1 == k];
  }
  return 0;
}