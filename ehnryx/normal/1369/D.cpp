//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define FILENAME sadcactussociety

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
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
/*
#ifdef ONLINE_JUDGE
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif
*/

  int N = 2e6 + 1;
  vector<pair<ll,ll>> dp(N);
  for(int i=3; i<N; i++) {
    dp[i].first = max(dp[i-1].first + 2*dp[i-2].first, dp[i-1].second + 2*dp[i-2].second + 4) % MOD;
    dp[i].second = (dp[i-1].first + 2*dp[i-2].first) % MOD;
  }

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    cout << dp[n].first << nl;
  }

	return 0;
}