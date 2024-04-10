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
  vector<vector<int>> a(2);
  REP(i, n * 2) {
    int ai; cin >> ai;
    a[ai & 1].emplace_back(i);
  }
  while (--n) {
    if (a[0].size() >= 2) {
      cout << a[0].back() + 1 << ' ';
      a[0].pop_back();
      cout << a[0].back() + 1 << '\n';
      a[0].pop_back();
    } else {
      cout << a[1].back() + 1 << ' ';
      a[1].pop_back();
      cout << a[1].back() + 1 << '\n';
      a[1].pop_back();
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}