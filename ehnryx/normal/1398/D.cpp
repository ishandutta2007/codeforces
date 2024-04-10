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

  int n[3];
  cin >> n[0] >> n[1] >> n[2];
  vector<int> a[3];
  for(int t=0; t<3; t++) {
    a[t].resize(n[t]+1);
    for(int i=1; i<=n[t]; i++) {
      cin >> a[t][i];
    }
    sort(a[t].begin(), a[t].end());
  }

  int dp[n[0]+1][n[1]+1][n[2]+1];
  for(int i=0; i<=n[0]; i++) {
    for(int j=0; j<=n[1]; j++) {
      for(int k=0; k<=n[2]; k++) {
        dp[i][j][k] = 0;
        if(i && j) {
          dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + a[0][i] * a[1][j]);
        }
        if(i && k) {
          dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + a[0][i] * a[2][k]);
        }
        if(j && k) {
          dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + a[1][j] * a[2][k]);
        }
      }
    }
  }
  cout << dp[n[0]][n[1]][n[2]] << nl;

  return 0;
}