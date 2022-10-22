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

  int n;
  cin >> n;
  vector<int> a(n+1);
  for(int i=1; i<=n; i++) {
    cin >> a[i];
  }

  vector<int> dp(2*n+1, INF);
  dp[n] = 0;
  for(int i=1; i<=n; i++) {
    vector<int> ndp(2*n+1, INF);
    for(int j=0; j<=2*n; j++) {
      if(dp[j] == INF) continue;
      if(a[i] == 1) {
        if(j < n) {
          ndp[j+1] = min(ndp[j+1], dp[j] + i);
        } else {
          ndp[j+1] = min(ndp[j+1], dp[j] - i);
        }
      } else {
        if(j > n) {
          ndp[j-1] = min(ndp[j-1], dp[j] + i);
        } else {
          ndp[j-1] = min(ndp[j-1], dp[j] - i);
          ndp[j] = min(ndp[j], dp[j]);
        }
      }
    }
    dp = move(ndp);
  }
  cout << dp[n] << nl;

  return 0;
}