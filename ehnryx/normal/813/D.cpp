#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
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
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 5e3 + 1;
int a[N], m[N], dp[N][N];

const int M = 1e5 + 2;
int val[M], mod[7];

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		m[i] = a[i] % 7;
	}

	for(int i=1; i<=n; i++) {
		int res = 1;
		res = max(res, val[a[i]+1] + 1);
		res = max(res, val[a[i]-1] + 1);
		res = max(res, mod[m[i]] + 1);
		dp[i][0] = dp[0][i] = res;
		val[a[i]] = max(val[a[i]], res);
		mod[m[i]] = max(mod[m[i]], res);
	}

	for(int j=0; j<=n; j++) {
		for(int i=1; i<=n; i++) {
			val[a[i]] = mod[m[i]] = 0;
		}
		for(int i=1; i<=n; i++) {
			if(i > j) {
				int res = dp[j][0] + 1;
				res = max(res, val[a[i]-1] + 1);
				res = max(res, val[a[i]+1] + 1);
				res = max(res, mod[m[i]] + 1);
				dp[j][i] = dp[i][j] = res;
			}
			val[a[i]] = max(val[a[i]], dp[j][i]);
			mod[m[i]] = max(mod[m[i]], dp[j][i]);
		}
	}

	int ans = 0;
	for(int i=0; i<=n; i++) {
		for(int j=0; j<i; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << nl;

	return 0;
}