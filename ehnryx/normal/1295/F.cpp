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

ll power(ll n, ll e, ll m) {
	ll r = 1;
	for(;e;e/=2) {
		if(e&1) r = r*n % m;
		n = n*n % m;
	}
	return r;
}

ll inverse(ll n, ll m) {
	return power(n, m-2, m);
}

const int N = 50 + 1;
ll dp[N][2*N];
ll cnt[N][N][2*N];

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	vector<int> a(n+1), b(n+1);
	map<int,int> remap;
	ll total = 1;
	for(int i=1; i<=n; i++) {
		cin >> a[i] >> b[i];
		remap[a[i]];
		remap[b[i]+1];
		total = total * (b[i]-a[i]+1) % MOD;
	}

	vector<int> value;
	int rid = 0;
	for(auto& it : remap) {
		it.second = rid++;
		value.push_back(it.first);
	}

	vector<int> lower(n+1), upper(n+1);
	for(int i=1; i<=n; i++) {
		lower[i] = remap[a[i]];
		upper[i] = remap[b[i]+1];
	}

	for(int i=1; i<=n; i++) {
		int lb = lower[i];
		int ub = upper[i];
		for(int j=i; j<=n; j++) {
			lb = max(lb, lower[j]);
			ub = min(ub, upper[j]);
			for(int k=lb; k<ub; k++) {
				int len = value[k+1] - value[k];
				ll rising = 1;
				ll fact = 1;
				for(int v=i; v<=j; v++) {
					rising = rising * (len + v-i) % MOD;
					fact = fact * (v-i + 1) % MOD;
				}
				cnt[i][j][k] = rising * inverse(fact, MOD) % MOD;
			}
		}
	}

	dp[0][rid-1] = 1;
	for(int i=1; i<=n; i++) {
		for(int j=0; j<rid; j++) {
			for(int pi=0; pi<i; pi++) {
				for(int pj=j+1; pj<rid; pj++) {
					dp[i][j] += dp[pi][pj] * cnt[pi+1][i][j] % MOD;
				}
			}
			dp[i][j] %= MOD;
		}
	}

	ll ans = 0;
	for(int j=0; j<rid; j++) {
		ans += dp[n][j];
	}
	ans = ans % MOD * inverse(total, MOD) % MOD;
	cout << ans << nl;

	return 0;
}