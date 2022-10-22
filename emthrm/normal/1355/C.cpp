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
  int a, b, c, d; cin >> a >> b >> c >> d;
  ll ans = 0;
  FOR(z, c, d + 1) {
    int l = max(z + 1 - c, a);
    if (b < l) continue;
    // cout << z << ": " <<  l << ' ' << b << '\n';
    int l_cnt = c - max(z + 1 - l, b) + 1, r_cnt = c - max(z + 1 - b, b) + 1;
    ans += 1LL * (r_cnt - l_cnt + 1) * (l_cnt + r_cnt) / 2 + 1LL * r_cnt * ((b - l + 1) - (r_cnt - l_cnt + 1));
    // cout << 1LL * (r_cnt - l_cnt + 1) * (l_cnt + r_cnt) / 2 + 1LL * r_cnt * ((b - l + 1) - (r_cnt - l_cnt + 1)) << '\n';
  }
  cout << ans << '\n';
}