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
const long double EPS = 1e-15;
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

int main() {
  int n; cin >> n;
  ll ans = 1LL * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
  vector<int> x(n), y(n); REP(i, n) cin >> x[i] >> y[i];
  REP(i, n) {
    vector<pair<long double, pair<int, int> > > theta;
    REP(j, n) {
      if (j == i) continue;
      theta.emplace_back(atan2l(y[j] - y[i], x[j] - x[i]), make_pair(x[j] - x[i], y[j] - y[i]));
      if (theta.back().first < 0) theta.back().first += 2 * M_PI;
    }
    sort(ALL(theta));
    REP(j, n - 1) theta.emplace_back(theta[j].first + 2 * M_PI, theta[j].second);
    int j = 0;
    REP(k, n - 1) {
      while (j < k + n - 1 && 1LL * theta[k].second.first * theta[j].second.second - 1LL * theta[j].second.first * theta[k].second.second >= 0) ++j;
      ll width = j - k - 1;
      // cout << i << ' ' << k << ' ' << j << '\n';
      if (width >= 3) ans -= width * (width - 1) * (width - 2) / 6;
    }
  }
  cout << ans << '\n';
  return 0;
}