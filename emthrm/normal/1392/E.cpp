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
  vector a(n, vector(n, 0LL));
  for (int j = 1; j < n; j += 2) REP(i, n) a[i][j] = 1LL << (j - 1 + i);
  REP(i, n) REP(j, n) assert(a[i][j] <= 10000000000000000);
  REP(i, n) REP(j, n) {
    cout << a[i][j];
    if (j + 1 == n) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  int q; cin >> q;
  while (q--) {
    ll k; cin >> k;
    int y = 0, x = 0;
    vector<pair<int, int>> ans{{y, x}};
    while (x + 1 < n) {
      int i = y + x;
      for (; i < 60; ++i) {
        if (k >> i & 1) break;
      }
      assert(i < 60);
      int j = i + 1;
      for (; j < 60; ++j) {
        if (!(k >> j & 1)) break;
      }
      if (j == 60) j = i + 1;
      while (y + x < i) ans.emplace_back(++y, x);
      ans.emplace_back(y, ++x);
      while (y + x < j) ans.emplace_back(++y, x);
      if (x + 1 < n) ans.emplace_back(y, ++x);
    }
    while (y + 1 < n) ans.emplace_back(++y, x);
    assert(ans.size() == n * 2 - 1);
    for (auto [r, c] : ans) cout << r + 1 << ' ' << c + 1 << endl;
  }
  return 0;
}