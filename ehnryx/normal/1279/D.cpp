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

const int N = 1e6+1;
int k[N];
vector<int> a[N];
int cnt[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> k[i];
		a[i].resize(k[i]);
		for(int j=0; j<k[i]; j++) {
			cin >> a[i][j];
			cnt[a[i][j]]++;
		}
	}

	ll ans = 0;
	for(int i=0; i<n; i++) {
		ll cur = 0;
		for(int j=0; j<k[i]; j++) {
			cur += cnt[a[i][j]];
		}
		ans += (cur % MOD) * inverse(k[i]) % MOD;
	}
	ans = (ans % MOD) * inverse((ll)n*n%MOD) % MOD;
	cout << ans << nl;

	return 0;
}