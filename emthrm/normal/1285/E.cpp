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

void solve() {
  int n; cin >> n;
  vector<ll> l(n), r(n), comp(n * 2);
  REP(i, n) {
    cin >> l[i] >> r[i];
    l[i] *= 2;
    (r[i] *= 2) += 1;
    comp[i] = l[i];
    comp[n + i] = r[i];
  }
  comp.emplace_back(-LINF);
  comp.emplace_back(LINF);
  sort(ALL(comp));
  unique(comp);
  REP(i, n) {
    l[i] = lower_bound(ALL(comp), l[i]) - comp.begin();
    r[i] = lower_bound(ALL(comp), r[i]) - comp.begin();
  }
  int m = comp.size();
  vector<vector<int> > ins(m), del(m);
  REP(i, n) {
    ins[l[i]].emplace_back(i);
    del[r[i]].emplace_back(i);
  }
  vector<int> imos(m, 0);
  vector<vector<int> > pos(n);
  set<int> st;
  REP(i, m) {
    for (int e : del[i]) st.erase(e);
    for (int e : ins[i]) st.emplace(e);
    imos[i] = st.size();
    if (st.size() == 1) pos[*st.begin()].emplace_back(i);
  }
  int base = 0;
  FOR(i, 1, m) base += imos[i - 1] == 0 && imos[i] > 0;
  int ans = 0;
  REP(i, n) {
    int plus = 0, idx = 0;
    for (int j = 0; j < pos[i].size();) {
      int k = j + 1;
      while (k < pos[i].size() && pos[i][k] - pos[i][k - 1] == 1) ++k;
      plus += imos[pos[i][j] - 1] > 0 && imos[pos[i][k - 1] + 1] > 0;
      j = k;
    }
    chmax(ans, base + plus - (imos[l[i] - 1] == 0 && imos[r[i]] == 0 && pos[i].size() == r[i] - l[i]));
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}