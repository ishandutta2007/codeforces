#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;

	ll dp[m+1][n+1];
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			for(int k=0; k<=j; k++) {
				dp[i][j] += dp[i-1][k];
			}
			dp[i][j] %= MOD;
		}
	}

	ll ans = 0;
	for(int a=1; a<=n; a++) {
		for(int b=a; b<=n; b++) {
			ans += dp[m][a] * dp[m][n-b+1] % MOD;
		}
	}
	ans %= MOD;
	cout << ans << nl;

	return 0;
}