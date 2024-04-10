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
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  vector<int> a(n), c(n); REP(i, n) cin >> a[i] >> c[i];
  vector<int> ord(n);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&](int l, int r) -> bool { return a[l] < a[r]; });
  vector<ll> dp(n, LINF);
  dp[ord[0]] = 0;
  priority_queue<pair<int, ll>, vector<pair<int, ll>>, greater<pair<int, ll>>> que;
  que.emplace(a[ord[0]] + c[ord[0]], -(a[ord[0]] + c[ord[0]]));
  multiset<ll> st{0};
  ll mn = LINF;
  FOR(_, 1, n) {
    int i = ord[_];
    while (!que.empty() && que.top().first <= a[i]) {
      chmin(mn, que.top().second);
      st.erase(st.lower_bound(que.top().second));
      que.pop();
    }
    if (!st.empty()) chmin(dp[i], *st.begin());
    chmin(dp[i], mn + a[i]);
    que.emplace(a[i] + c[i], dp[i] - (a[i] + c[i]));
    st.emplace(dp[i]);
  }
  cout << dp[ord[n - 1]] + accumulate(ALL(c), 0LL) << '\n';
  return 0;
}