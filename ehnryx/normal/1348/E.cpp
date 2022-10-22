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
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 500 + 1;
int A[N], B[N];
ll sum[N], mod[N];
ll dp[N][N];

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		cin >> A[i] >> B[i];
		sum[i] = sum[i-1] + A[i] + B[i];
		mod[i] = sum[i] % k;
	}

	memset(dp, 0xff^0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i=1; i<=n; i++) {
		int tmod = (A[i] + B[i]) % k;
		for(int r=0; r<k; r++) {
			int b = mod[i] - r;
			if(b < 0) b += k;
			for(int red=0; red<k; red++) {
				int blue = tmod - red;
				if(blue < 0) blue += k;
				if(red > A[i] || blue > B[i]) continue;
				int pr = (r - red);
				int pb = (b - blue);
				if(pr < 0) pr += k;
				if(pb < 0) pb += k;
				dp[i][r] = max(dp[i][r], dp[i-1][pr] + (pr > r) + (pb > b) + (A[i]+B[i]-(red+blue))/k);
			}
		}
	}

	ll ans = 0;
	for(int r=0; r<k; r++) {
		ans = max(ans, dp[n][r]);
	}
	cout << ans << nl;

	return 0;
}