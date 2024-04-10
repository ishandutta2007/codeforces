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

int main() {
  ll x0, y0, ax, ay, bx, by, xs, ys, t; cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
  vector<pair<ll, ll> > points{{x0, y0}};
  while (true) {
    ll prev_x, prev_y; tie(prev_x, prev_y) = points.back();
    if (log10(ax) + log10(prev_x) > 18) break;
    ll x = ax * prev_x + bx;
    if (log10(ay) + log10(prev_y) > 18) break;
    ll y = ay * prev_y + by;
    points.emplace_back(x, y);
  }
  int n = points.size(), ans = 0;
  REP(i, n) FOR(j, i, n) {
    ll tm = abs(points[i].first - xs) + abs(points[i].second - ys);
    if (tm > t) continue;
    FOR(k, i + 1, j + 1) {
      tm += abs(points[k].first - points[k - 1].first) + abs(points[k].second - points[k - 1].second);
      if (tm > t) break;
    }
    if (tm <= t) chmax(ans, j - i + 1);
    tm = abs(points[j].first - xs) + abs(points[j].second - ys);
    if (tm > t) continue;
    for (int k = j - 1; k >= i; --k) {
      tm += abs(points[k].first - points[k + 1].first) + abs(points[k].second - points[k + 1].second);
      if (tm > t) break;
    }
    if (tm <= t) chmax(ans, j - i + 1);
  }
  cout << ans << '\n';
  return 0;
}