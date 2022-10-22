//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
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

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while(T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n+1);
    a[0] = x;
    for(int i=1; i<=n; i++) {
      cin >> a[i];
    }
    int m = *max_element(a.begin(), a.end());

    vector dp(n+1, vector<int>(m+1, INF));
    dp[0][0] = 0;
    for(int i=0; i<n; i++) {
      for(int v=0; v<=m; v++) {
        if(dp[i][v] == INF) continue;
        for(int j=i+1; j<=n; j++) {
          if(a[j] > a[i] && a[i] >= a[j-1] && (j == i+1 || v <= a[i+1])) {
            dp[j][a[i]] = min(dp[j][a[i]], dp[i][v] + 1);
          }
          if(j > i+1 && a[j] < a[j-1]) break;
        }
      }
    }

    /*
    for(int i=1; i<=n; i++) {
      for(int j=i-1; j>=0; j--) {
        for(int v=0; v<=a[j+1]; v++) {
          if(a[j] < a[i] && a[i-1] <= a[j]) {
            dp[i][a[j]] = min(dp[i][a[j]], dp[j][v] + 1);
          }
        }
        if(a[j] > a[i]) break;
      }
    }
    */

    int ans = *min_element(dp[n].begin(), dp[n].end());
    for(int i=n-1; i>=0; i--) {
      for(int v=0; v<=a[i+1]; v++) {
        ans = min(ans, dp[i][v]);
      }
      if(a[i] > a[i+1]) break;
    }

    if(ans == INF) {
      cout << -1 << nl;
    } else {
      cout << ans << nl;
    }
  }

  return 0;
}