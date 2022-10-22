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
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  int moves = 0, alice = 0, bob = 0, l = 0, r = n - 1, prev = 0;
  for (bool is_alice = true; l <= r; is_alice = !is_alice, ++moves) {
    int cur = 0;
    if (is_alice) {
      while (l <= r && cur <= prev) cur += a[l++];
      alice += cur;
    } else {
      while (l <= r && cur <= prev) cur += a[r--];
      bob += cur;
    }
    prev = cur;
  }
  cout << moves << ' ' << alice << ' ' << bob << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}