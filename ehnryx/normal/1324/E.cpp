//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
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
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, h, l, r;
	cin >> n >> h >> l >> r;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	vector<vector<int>> dp(n+1, vector<int>(h, -INF));
	dp[0][0] = 0;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<h; j++) {
			int full = (j + h-a[i-1]) % h;
			int small = (j + h-(a[i-1]-1)) % h;
			dp[i][j] = max(dp[i-1][full], dp[i-1][small]) + (l<=j && j<=r);
		}
	}

	int ans = 0;
	for(int j=0; j<h; j++) {
		ans = max(ans, dp[n][j]);
	}
	cout << ans << nl;

	return 0;
}