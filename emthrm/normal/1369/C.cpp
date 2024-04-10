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
  int n, k; cin >> n >> k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<pair<int, int>> w(k);
  REP(i, k) {
    cin >> w[i].first;
    w[i].second = i;
  }
  sort(ALL(a), greater<int>());
  sort(ALL(w), greater<pair<int, int>>());
  vector<vector<int>> fri(k);
  for (int i = k - 1; i >= 0; --i) {
    fri[w[i].second].emplace_back(a[k - 1 - i]);
    --w[i].first;
  }
  vector<int> idx;
  for (int i = w.size() - 1; i >= 0; --i) {
    REP(_, w[i].first) idx.emplace_back(w[i].second);
  }
  FOR(i, k, n) fri[idx[i - k]].emplace_back(a[i]);
  ll ans = 0;
  REP(i, k) ans += *min_element(ALL(fri[i])) + *max_element(ALL(fri[i]));
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}