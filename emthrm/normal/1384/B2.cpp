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

const int L = 200;

void solve() {
  int n, k, l; cin >> n >> k >> l;
  vector<int> d(n); REP(i, n) cin >> d[i];
  for (int i = 0; i < n;) {
    if (d[i] + k <= l) {
      ++i;
      continue;
    }
    if (d[i] > l) {
      cout << "No\n";
      return;
    }
    int j = i + 1;
    while (j < n && d[j] + k > l) ++j;
    ll left = l - d[j - 1] + 1, right = 2LL * k - (l - d[j - 1] + 1);
    for (int m = j - 2; m >= i; --m) {
      left = min(left - 1, 1LL + l - d[m]);
      right = max(right - 1, 2LL * k - (l - d[m] + 1));
    }
    if (right - left + 1 >= 2LL * k) {
      cout << "No\n";
      return;
    }
    i = j + 1;
  }
  cout << "Yes\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}