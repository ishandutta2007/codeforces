#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

constexpr char nl = '\n';
constexpr ll INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9L;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  s.insert(s.begin(), 0);
  t.insert(t.begin(), 0);

  vector dp(n+1, vector(m+1, vector(4, vector<ll>(2))));
  for(int i=0; i<=n; i++) {
    for(int j=0; j<=m; j++) {
      if(i > 0) {
        dp[i][j][0b01][0] += 1;
        if(i-1 == 0 || s[i-1] != s[i]) {
          dp[i][j][0b01][0] += dp[i-1][j][0b01][0];
          dp[i][j][0b11][0] += dp[i-1][j][0b11][0];
        }
        if(j == 0 || t[j] != s[i]) {
          dp[i][j][0b11][0] += dp[i-1][j][0b10][1] + dp[i-1][j][0b11][1];
        }
      }
      if(j > 0) {
        dp[i][j][0b10][1] += 1;
        if(j-1 == 0 || t[j-1] != t[j]) {
          dp[i][j][0b10][1] += dp[i][j-1][0b10][1];
          dp[i][j][0b11][1] += dp[i][j-1][0b11][1];
        }
        if(i == 0 || s[i] != t[j]) {
          dp[i][j][0b11][1] += dp[i][j-1][0b01][0] + dp[i][j-1][0b11][0];
        }
      }
      for(int bm=0; bm<4; bm++) {
        for(int f=0; f<2; f++) {
          dp[i][j][bm][f] %= MOD;
        }
      }
    }
  }

  ll ans = 0;
  for(int i=0; i<=n; i++) {
    for(int j=0; j<=m; j++) {
      ans += dp[i][j][0b11][0] + dp[i][j][0b11][1];
    }
  }
  ans %= MOD;
  cout << ans << nl;

  return 0;
}