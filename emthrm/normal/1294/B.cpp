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

void solve() {
  int n; cin >> n;
  vector<pair<int, int> > xy(n); REP(i, n) cin >> xy[i].first >> xy[i].second;
  sort(ALL(xy));
  int x = 0, y = 0;
  string ans = "";
  REP(i, n) {
    if (xy[i].first < x || xy[i].second < y) {
      cout << "NO\n";
      return;
    }
    while (x < xy[i].first) {
      ++x;
      ans += 'R';
    }
    while (y < xy[i].second) {
      ++y;
      ans += 'U';
    }
  }
  cout << "YES\n" << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}