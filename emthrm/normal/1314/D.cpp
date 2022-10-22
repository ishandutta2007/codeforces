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

struct Timer {
  Timer() { reset(); }
  void reset() { beg = chrono::high_resolution_clock::now(); }
  ll elapsed() {
    chrono::high_resolution_clock::time_point en = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(en - beg).count();
  }
private:
  chrono::high_resolution_clock::time_point beg;
} timer;

struct Xor128 {
  int rand() {
    unsigned t = x ^ (x << 11);
    x = y; y = z; z = w; w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    return static_cast<int>(w);
  }
  int rand(int ub) {
    int res = rand() % ub;
    return res < 0 ? res + ub : res;
  }
  int rand(int lb, int ub) { return lb + rand(ub - lb); }
  ll randll() {
    unsigned long long res = static_cast<unsigned long long>(rand()) << 32;
    return static_cast<ll>(res | rand());
  }
  ll randll(ll ub) {
    ll res = randll() % ub;
    return res < 0 ? res + ub : res;
  }
  ll randll(ll lb, ll ub) { return lb + randll(ub - lb); }
private:
  unsigned x = 123456789, y = 362436069, z = 521288629, w = static_cast<unsigned>(time(nullptr));
} xor128;

int main() {
  int n, k; cin >> n >> k;
  vector<vector<int> > d(n, vector<int>(n)); REP(i, n) REP(j, n) cin >> d[i][j];
  REP(i, n) d[i][i] = INF;
  int ans = INF;
  while (timer.elapsed() < 2900) {
    vector<bool> color(n, true);
    FOR(i, 1, n) color[i] = xor128.rand(2);
    vector<vector<int> > dist(k + 1, vector<int>(n, INF));
    dist[0][0] = 0;
    REP(i, k) REP(j, n) {
      REP(x, n) {
        if (color[j] != color[x]) chmin(dist[i + 1][x], dist[i][j] + d[j][x]);
      }
    }
    chmin(ans, dist[k][0]);
  }
  cout << ans << '\n';
  return 0;
}