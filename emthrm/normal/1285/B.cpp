#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n); REP(i, n) cin >> a[i];
    vector<ll> dp(n);
    dp[0] = max(a[0], 0);
    FOR(i, 1, n - 1) dp[i] = max(dp[i - 1] + a[i], 0LL);
    bool happy = accumulate(ALL(a), 0LL) > *max_element(dp.begin(), dp.begin() + n - 1);
    dp[1] = max(a[1], 0);
    FOR(i, 2, n) dp[i] = max(dp[i - 1] + a[i], 0LL);
    happy &= accumulate(ALL(a), 0LL) > *max_element(dp.begin() + 1, dp.end());
    cout << (happy ? "YES\n" : "NO\n");
  }
  return 0;
}