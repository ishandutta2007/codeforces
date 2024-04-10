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

ll add(ll a, ll b) {
  return min(a + b, LINF);
}

ll mul(ll a, ll b) {
  return log10(a) + log10(b) > 18.5 ? LINF : a * b;
}

void solve() {
  int n; ll k; cin >> n >> k;
  vector<ll> cycle(n + 1, 1);
  FOR(i, 3, n + 1) cycle[i] = mul(cycle[i - 1], i - 2);
  vector<ll> dp(n + 1, 0);
  dp[n] = 1;
  for (int i = n - 1; i >= 0; --i) {
    FOR(j, i + 1, n + 1) dp[i] = add(dp[i], mul(dp[j], cycle[j - i]));
  }
  if (dp[0] < k) {
    cout << "-1\n";
    return;
  }
  vector<int> ans(n, -1);
  vector<bool> used(n, false);
  for (int pos = 0; pos < n;) {
    FOR(j, pos + 1, n + 1) {
      ll pat = mul(dp[j], cycle[j - pos]);
      if (pat < k) {
        k -= pat;
        continue;
      }
      ans[pos] = j - 1;
      used[j - 1] = true;
      FOR(i, pos + 1, j) {
        FOR(val, pos, j - 1) {
          if (used[val] || i == val) continue;
          if (i + 1 != j) {
            int tmp = ans[val];
            while (tmp != -1 && tmp != i) tmp = ans[tmp];
            if (tmp == i) continue;
          }
          ll pat2 = mul(dp[j], cycle[j - i]);
          if (pat2 < k) {
            k -= pat2;
            continue;
          }
          ans[i] = val;
          used[val] = true;
          break;
        }
      }
      pos = j;
      break;
    }
  }
  REP(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}