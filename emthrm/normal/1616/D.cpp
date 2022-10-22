#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<ll> a(n); REP(i, n) cin >> a[i];
  int x; cin >> x;
  REP(i, n) a[i] -= x;
  int p = 0;
  pair<int, ll> q{-INF, -LINF};
  REP(i, n) {
    int r = -INF;
    pair<int, ll> s{-INF, -LINF};
    chmax(r, p);
    s = max(s, make_pair(p + 1, a[i]));
    chmax(r, q.first);
    if (q.second + a[i] >= 0) s = max(s, make_pair(q.first + 1, min(q.second + a[i], a[i])));
    swap(p, r);
    swap(q, s);
  }
  cout << max(p, q.first) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}