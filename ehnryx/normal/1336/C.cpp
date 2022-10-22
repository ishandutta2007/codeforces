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



// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	string s, t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();

	ll ans = 0;
	vector<ll> dp(n+1, 1);
	for(int i=0; i<n; i++) {
		vector<ll> ndp(n-i, 0);
		for(int j=0; i+j<n; j++) {
			if(j >= m || s[i] == t[j]) ndp[j] += dp[j+1];
			if(i+j >= m || s[i] == t[i+j]) ndp[j] += dp[j];
			ndp[j] %= MOD;
		}
		dp = move(ndp);
		if(i+1 >= m) {
			ans += dp[0];
		}
	}
	cout << ans % MOD << nl;

	return 0;
}