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

constexpr int X = 1000000;
int r[X + 2];
vector<pair<int, int>> aim[X + 2];

int main() {
  int n, m; cin >> n >> m;
  vector<int> a(n), b(n); REP(i, n) cin >> a[i] >> b[i];
  REP(i, X + 2) r[i] = -1;
  vector<int> d(m);
  REP(i, m) {
    int c; cin >> c >> d[i];
    chmax(r[d[i]], c);
  }
  for (int i = X - 1; i >= 0; --i) chmax(r[i], r[i + 1]);
  REP(i, n) REP(j, m) {
    if (b[i] <= d[j]) aim[d[j] - b[i] + 1].emplace_back(i, j);
  }
  multiset<int> st;
  REP(i, n) st.emplace(max(r[b[i]] - a[i] + 1, 0));
  vector<int> prev(n, -1);
  int ans = *st.rbegin();
  REP(y, X + 2) {
    if (!aim[y].empty()) {
      for (auto [i, j] : aim[y]) {
        int bef = (prev[i] == -1 ? r[b[i]] : r[d[prev[i]] + 1]) - a[i] + 1;
        st.erase(st.lower_bound(bef));
        prev[i] = j;
        st.emplace(max(r[d[j] + 1] - a[i] + 1, 0));
      }
      chmin(ans, y + *st.rbegin());
    }
  }
  cout << ans << '\n';
  return 0;
}