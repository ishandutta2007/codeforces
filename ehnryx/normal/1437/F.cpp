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

const int N = 5000 + 1;
ll ncr[N][N];
ll dp[N][N];
ll pre[N][N];

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

  for(int i=0; i<N; i++) {
    ncr[i][0] = ncr[i][i] = 1;
    for(int j=1; j<i; j++) {
      ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % MOD;
    }
  }

  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  vector<int> h(n);
  for(int i=0; i<n; i++) {
    h[i] = upper_bound(a.begin(), a.end(), a[i]/2) - a.begin();
  }

  dp[0][0] = 1;
  pre[0][0] = 1;
  for(int i=1; i<=n; i++) {
    pre[i][0] = 1;
    for(int j=1; j<=i; j++) {
      dp[i][j] = dp[i][j-1] * (h[i-1] - (j-2)) % MOD;
      dp[i][j] = (dp[i][j] + pre[h[i-1]][j-1]) % MOD;
      pre[i][j] = (pre[i-1][j] + dp[i][j]) % MOD;
    }
  }
  cout << dp[n][n] << nl;

  return 0;
}