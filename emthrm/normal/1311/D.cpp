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
  int a, b, c; cin >> a >> b >> c;
  int ans = INF, A = a, B = b, C = c;
  FOR(i, 1, 30001) {
    int now = abs(a - i);
    for (int j = i; j <= 30001; j += i) {
      int now2 = now + abs(b - j);
      int low = c / j * j;
      if (low > 0 && now2 + abs(c - low) < ans) {
        ans = now2 + abs(c - low);
        A = i; B = j; C = low;
      }
      if (now2 + abs(c - (low + j)) < ans) {
        ans = now2 + abs(c - (low + j));
        A = i; B = j; C = low + j;
      }
    }
  }
  cout << ans << '\n' << A << ' ' << B << ' ' << C << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}