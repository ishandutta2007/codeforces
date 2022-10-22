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
  int n, k; cin >> n >> k;
  vector<int> cnt(k, 0);
  while (n--) {
    int m; cin >> m;
    ++cnt[m - 1];
  }
  vector<int> c(k); REP(i, k) cin >> c[i];
  vector<vector<int>> ans(1);
  set<pair<int, int>> st{{0, 0}};
  for (int i = k - 1; i >= 0; --i) {
    for (; cnt[i] > 0; --cnt[i]) {
      if (st.begin()->first == c[i]) {
        st.emplace(1, ans.size());
        ans.emplace_back(vector<int>{i + 1});
      } else {
        int idx = st.begin()->second;
        st.erase(st.begin());
        ans[idx].emplace_back(i + 1);
        st.emplace(ans[idx].size(), idx);
      }
    }
  }
  cout << ans.size() << '\n';
  for (const vector<int> &t : ans) {
    cout << t.size() << ' ';
    REP(i, t.size()) cout << t[i] << " \n"[i + 1 == t.size()];
  }
  return 0;
}