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

int main() {
  int n; cin >> n;
  if (n & 1) {
    cout << "NO\n";
    return 0;
  }
  vector<ll> x(n), y(n); REP(i, n) cin >> x[i] >> y[i];
  x.emplace_back(x[0]);
  y.emplace_back(y[0]);
  vector<ll> X(n / 2), Y(n / 2);
  REP(i, n / 2) {
    X[i] = x[i + 1] - x[i];
    Y[i] = y[i + 1] - y[i];
  }
  FOR(i, n / 2, n) {
    int dist_x = x[i + 1] - x[i], dist_y = y[i + 1] - y[i];
    dist_x *= -1; dist_y *= -1;
    if (X[i - n / 2] != dist_x || Y[i - n / 2] != dist_y) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}