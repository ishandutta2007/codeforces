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

ll power(ll n, ll e) {
	ll r = 1;
	for(;e;e/=2) {
		if(e&1) r = r*n % MOD;
		n = n*n % MOD;
	}
	return r;
}

const int N = 36;
const int M = 15;
ll dp[N][N][1<<M];

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;

	vector<ll> b(m);
	for(int i=0; i<n; i++) {
		ll v;
		cin >> v;
		for(int j=0; j<m; j++) {
			if(!(v>>j & 1)) continue;
			if(b[j]) {
				v ^= b[j];
			} else {
				b[j] = v;
				break;
			}
		}
	}
	int k = accumulate(b.begin(), b.end(), 0, [](int c, ll v) {
		return c + !!v;
	});

	cerr<<"basis size: "<<k<<nl;

	if(m-k > 15) {
		assert(k <= 20);
		sort(b.begin(), b.end(), greater<ll>());
		while(!b.empty() && b.back() == 0) {
			b.pop_back();
		}

		ll f = power(2, n-k);
		vector<ll> ans(m+1);
		for(int bm=0; bm<1<<k; bm++) {
			ll val = 0;
			for(int j=0; j<k; j++) {
				if(bm & 1<<j) {
					val ^= b[j];
				}
			}
			ans[__builtin_popcountll(val)] += f;
		}
		for(int i=0; i<=m; i++) {
			cout << ans[i] % MOD << " ";
		}
		cout << nl;
		return 0;
	}

	for(int j=0; j<m; j++) {
		if(!b[j]) continue;
		for(int i=0; i<m; i++) {
			if(i != j && (b[i]>>j & 1)) {
				b[i] ^= b[j];
			}
		}
	}

	dp[0][0][0] = power(2, n-k);
	for(int i=0; i<m; i++) {
		if(!b[i]) {
			swap(dp[i], dp[i+1]);
			continue;
		}
		for(int j=0; j<=m; j++) {
			for(int bm=0; bm<1<<(m-k); bm++) {
				dp[i+1][j][bm] = dp[i][j][bm];
				if(j > 0) {
					int val = 0;
					for(int t=0, r=0; t<m; t++) {
						if(b[t]) continue;
						val |= (b[i] >> t & 1) << r++;
					}
					assert(val < 1<<(m-k));
					dp[i+1][j][bm] = (dp[i+1][j][bm] + dp[i][j-1][bm^val]) % MOD;
				}
			}
		}
	}

	vector<ll> ans(m+1);
	for(int j=0; j<=m; j++) {
		for(int bm=0; bm<1<<(m-k); bm++) {
			ans[j+__builtin_popcount(bm)] += dp[m][j][bm];
		}
	}
	for(int i=0; i<=m; i++) {
		cout << ans[i] % MOD << " ";
	}
	cout << nl;

	return 0;
}