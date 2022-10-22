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
  vector<int> a(n), b(n); REP(i, n) cin >> a[i] >> b[i], --a[i], --b[i];
  vector<vector<pair<int, int>>> right(n);
  REP(i, n) right[b[i]].emplace_back(a[i], i);
  set<int> st;
  REP(i, n) st.emplace(i);
  vector<int> ans(n);
  REP(i, n) {
    sort(ALL(right[i]));
    for (auto [left, idx] : right[i]) {
      ans[idx] = *st.lower_bound(left);
      assert(ans[idx] <= i);
      st.erase(ans[idx]);
    }
  }
  vector<int> pos(n);
  REP(i, n) pos[ans[i]] = i;
  vector<vector<pair<int, int>>> ins(n);
  REP(i, n) ins[a[i]].emplace_back(ans[i], i);
  set<pair<int, int>> mn;
  REP(i, n) {
    for (auto e : ins[i]) mn.emplace(e);
    int idx = pos[i];
    mn.erase(make_pair(ans[idx], idx));
    if (!mn.empty() && mn.begin()->first <= b[idx]) {
      int idx2 = mn.begin()->second;
      cout << "NO\n";
      REP(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
      swap(ans[idx], ans[idx2]);
      REP(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
      return 0;
    }
  }
  cout << "YES\n";
  REP(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
  return 0;
}