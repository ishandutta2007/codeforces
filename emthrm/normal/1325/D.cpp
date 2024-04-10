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

int main() {
  ll u, v; cin >> u >> v;
  if (u == v) {
    if (u == 0) {
      cout << "0\n";
    } else {
      cout << "1\n" << u << '\n';
    }
    return 0;
  }
  ll x = v - u;
  if (x < 0 || x & 1) {
    cout << "-1\n";
    return 0;
  }
  if (x % 2 == 0 && ((x >> 1) & u) == 0) {
    ll a = x >> 1, b = a;
    REP(i, 60) {
      if (u >> i & 1) a |= 1LL << i;
    }
    cout << "2\n" << a << ' ' << b << '\n';
    return 0;
  }
  cout << "3\n" << u << ' ' << x / 2 << ' ' << x / 2 << '\n';
  return 0;
}