//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
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
const ld EPS = 1e-11;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e3 + 2;
int a[N], cost[N], ret[2*N];
int dp[2*N][N]; // val, cnt

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> cost[i];
	}
	for(int i=1; i<=n+m; i++) {
		cin >> ret[i];
	}

	fill(&dp[0][0], &dp[0][0]+2*N*N, -INF);
	for(int v=1; v<=n+m; v++) {
		dp[v][0] = 0;
	}

	for(int i=n; i>=1; i--) {
		int v = a[i];
		for(int j=n-i+1; j>=1; j--) {
			dp[v][j] = max(dp[v][j], dp[v][j-1] + ret[v] - cost[i]);
		}
		for(int ub=(n-i+1)/2, add=1; v+add<=n+m; add++, ub/=2) {
			for(int j=ub; j>=0; j--) {
				dp[v+add][j] = max(dp[v+add][j], dp[v+add-1][2*j] + j*ret[v+add]);
				dp[v+add][j] = max(dp[v+add][j], dp[v+add-1][2*j+1] + j*ret[v+add]);
			}
		}
	}

	int ans = 0;
	for(int i=1; i<=n+m; i++) {
		ans = max(ans, dp[i][0]);
	}
	cout << ans << nl;

	return 0;
}