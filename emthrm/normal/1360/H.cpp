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
  vector<ll> p2(61, 1);
  FOR(i, 1, 61) p2[i] = p2[i - 1] * 2;
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    REP(i, n) cin >> a[i];
    sort(ALL(a));
    ll k = p2[m] - n, idx = (k - 1) / 2;
    ll lb = 0, ub = p2[m];
    while (ub - lb > 1) {
      ll mid = (lb + ub) >> 1;
      string s = bitset<60>(mid).to_string();
      reverse(ALL(s));
      s.resize(m);
      reverse(ALL(s));
      (mid - (lower_bound(ALL(a), s) - a.begin()) <= idx ? lb : ub) = mid;
    }
    string ans = bitset<60>(lb).to_string();
    reverse(ALL(ans));
    ans.resize(m);
    reverse(ALL(ans));
    cout << ans << '\n';
  }
  return 0;
}