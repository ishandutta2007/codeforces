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

int mex(vector<int> a) {
  sort(ALL(a));
  a.erase(unique(ALL(a)), a.end());
  REP(i, a.size()) {
    if (a[i] != i) return i;
  }
  return a.size();
}

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector fixed(n, false);
  REP(i, n) fixed[i] = a[i] == i;
  int cnt = count(ALL(fixed), true);
  vector<int> ans;
  while (cnt < n) {
    int m = mex(a);
    if (m == n) {
      REP(i, n) {
        if (!fixed[i]) {
          REP(j, n) {
            if (a[j] == i) {
              a[j] = m;
              ans.emplace_back(j);
              break;
            }
          }
          break;
        }
      }
    } else {
      a[m] = m;
      fixed[m] = true;
      ++cnt;
      ans.emplace_back(m);
    }
    // cout << m << '\n';
    // REP(i, n) cout << a[i] << " \n"[i + 1 == n];
  }
  int k = ans.size();
  assert(k <= n * 2);
  cout << k << '\n';
  REP(i, k) cout << ans[i] + 1 << " \n"[i + 1 == k];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}