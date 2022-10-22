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
  int n, k; cin >> n >> k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  int lb = 0, ub = *max_element(ALL(a));
  while (ub - lb > 1) {
    int mid = (lb + ub) >> 1;
    bool ok = false;
    {
      int sz = 0;
      REP(i, n) {
        if (sz % 2 == 0) {
          if (a[i] <= mid) ++sz;
        } else {
          ++sz;
        }
      }
      ok |= sz >= k;
    }
    {
      int sz = 0;
      REP(i, n) {
        if (sz % 2 == 1) {
          if (a[i] <= mid) ++sz;
        } else {
          ++sz;
        }
      }
      ok |= sz >= k;
    }
    (ok ? ub : lb) = mid;
  }
  cout << ub << '\n';
  return 0;
}