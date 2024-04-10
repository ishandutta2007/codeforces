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
  int n; cin >> n;
  vector<vector<int>> p(n - 1);
  vector<vector<int>> contain(n);
  REP(i, n - 1) {
    int k; cin >> k;
    p[i].resize(k);
    REP(j, k) {
      cin >> p[i][j]; --p[i][j];
      contain[p[i][j]].emplace_back(i);
    }
  }
  // REP(i, n) {
  //   for (int e : contain[i]) cout << e << ' ';
  //   cout << endl;
  // }
  function<bool(int)> sub = [&](int p0) {
    vector<set<int>> st(n);
    st[0].emplace(p0);
    vector<int> ans(n), exist(n - 1, -1);
    REP(i, n) {
      // cout << p0 << ' ' << i << " : ";
      // REP(j, n - 1) cout << exist[j] << ' ';
      // cout << endl;
      if (st[i].empty() || st[i].size() >= 2) return false;
      ans[i] = *st[i].begin();
      for (int e : contain[ans[i]]) {
        if (exist[e] == -1) {
          int idx = i - 1 + p[e].size();
          if (!st[idx].empty()) return false;
          exist[e] = idx;
          for (int e2 : p[e]) st[idx].emplace(e2);
        }
        st[exist[e]].erase(ans[i]);
      }
    }
    REP(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
    return true;
  };
  REP(i, n) {
    if (sub(i)) return;
  }
  assert(false);
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}