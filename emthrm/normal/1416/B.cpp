#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  vector<ll> a(n); REP(i, n) cin >> a[i];
  ll sum = accumulate(ALL(a), 0LL);
  if (sum % n > 0) {
    cout << "-1\n";
    return;
  }
  sum /= n;
  vector<int> I, J;
  vector<ll> X;
  FOR(i, 1, n) {
    if (a[i] % (i + 1) > 0) {
      ll tar = (a[i] + (i + 1) - 1) / (i + 1) * (i + 1);
      assert(a[0] >= tar - a[i]);
      I.emplace_back(0);
      J.emplace_back(i);
      X.emplace_back(tar - a[i]);
      a[0] -= tar - a[i];
      a[i] = tar;
    }
    I.emplace_back(i);
    J.emplace_back(0);
    X.emplace_back(a[i] / (i + 1));
    a[0] += a[i];
    a[i] = 0;
  }
  FOR(i, 1, n) {
    I.emplace_back(0);
    J.emplace_back(i);
    X.emplace_back(sum);
  }
  // REP(i, n) assert(a[i] == sum);
  int k = I.size();
  // assert(k <= n * 3);
  cout << k << '\n';
  REP(i, k) cout << I[i] + 1 << ' ' << J[i] + 1 << ' ' << X[i] << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}