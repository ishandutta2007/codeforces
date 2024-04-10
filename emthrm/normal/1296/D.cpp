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
  int n; ll a, b, k; cin >> n >> a >> b >> k;
  vector<ll> h(n); REP(i, n) cin >> h[i];
  int ans = 0;
  vector<int> last;
  REP(i, n) {
    h[i] -= h[i] / (a + b) * (a + b);
    if (h[i] == 0) {
      last.emplace_back((b + a - 1) / a);
      continue;
    }
    h[i] -= a;
    if (h[i] <= 0) {
      ++ans;
    } else {
      last.emplace_back((h[i] + a - 1) / a);
    }
  }
  sort(ALL(last));
  for (int e : last) {
    if (k >= e) {
      k -= e;
      ++ans;
    }
  }
  cout << ans << '\n';
  return 0;
}