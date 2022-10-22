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
const ll MOD = 998244353;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll power(ll n, ll e) {
	ll r = 1;
	for(;e;e/=2) {
		if(e&1) r = r*n % MOD;
		n = n*n % MOD;
	}
	return r;
}

ll inverse(ll n) {
	return power(n, MOD-2);
}

const int K = 5e3+1;
ll ncr[K][K], dp[K];
ll fall[K], invf[K];

void init() {
	for(int i=0; i<K; i++) {
		ncr[i][0] = ncr[i][i] = 1;
		for(int j=1; j<i; j++) {
			ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % MOD;
		}
	}
}

ll choosem(int g) {
	return fall[g] * invf[g] % MOD;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	init();

	int n, m, k;
	cin >> n >> m >> k;
	swap(n,m);

	invf[0] = 1;
	fall[0] = 1;
	for(int i=1; i<K; i++) {
		invf[i] = invf[i-1] * inverse(i) % MOD;
		fall[i] = fall[i-1] * (m-i+1) % MOD;
	}

	dp[1] = 1;
	for(int g=2; g<=min(m,k); g++) {
		dp[g] = power(g, k);
		for(int i=g-1; i>0; i--) {
			dp[g] -= dp[i] * ncr[g][i] % MOD;
		}
		dp[g] = (dp[g] % MOD + MOD) % MOD;
	}

	ll invn = inverse(n);
	ll ans = 0;
	for(int g=1; g<=min(m,k); g++) {
		ans += dp[g] * choosem(g) % MOD * power(invn, g) % MOD;
	}
	ans = (ans % MOD + MOD) % MOD;
	cout << ans << nl;

	return 0;
}