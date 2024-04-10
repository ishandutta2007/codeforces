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
random_device _rd; mt19937 rng(_rd());



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

  int n, m;
  cin >> n >> m;
  vector dp(n+1, vector<ll>(n+2));
  dp[0][0] = 1;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=i; j++) {
      // new segment
      dp[i][j] += dp[i-1][j-1] * j;
      // extend segment by 1
      dp[i][j] += dp[i-1][j] * 2*j;
      // extend segment by 2
      if(i >= 2) dp[i][j] += dp[i-2][j] * 2*j;
      // join segments with distance 2
      if(i >= 2) dp[i][j] += dp[i-2][j+1] * 2*j;
      // join segments with distance 3
      if(i >= 3) dp[i][j] += dp[i-3][j+1] * j;
      // mod
      dp[i][j] %= m;
    }
  }
  cout << dp[n][1] << nl;

  return 0;
}