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
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  if (n & 1) {
    if (a[n / 2] != b[n / 2]) {
      cout << "No\n";
      return;
    }
    a.erase(a.begin() + n / 2);
    b.erase(b.begin() + n / 2);
    --n;
  }
  vector<pair<int, int>> a2;
  REP(i, n / 2) a2.emplace_back(minmax(a[i], a[n - 1 - i]));
  sort(ALL(a2));
  vector<pair<int, int>> b2;
  REP(i, n / 2) b2.emplace_back(minmax(b[i], b[n - 1 - i]));
  sort(ALL(b2));
  REP(i, n / 2) {
    if (a2[i] != b2[i]) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}