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
const ll MOD = 1e9 + 7;
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

const int N = 1e6 + 1;
int a[N];
int cur[N];

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n, p;
		cin >> n >> p;
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		if(p == 1) {
			cout << n%2 << nl;
			continue;
		}
		sort(a, a+n);

		int have = -1;
		vector<int> put;
		for(int i=n-1; i>=0; i--) {
			if(have == -1) {
				have = a[i];
			} else {
				put.push_back(a[i]);
				for(int j=a[i]; ++cur[j]==p; j++) {
					cur[j] = 0;
					put.push_back(j+1);
				}
				if(cur[have] == 1) {
					cur[have] = 0;
					have = -1;
					put.clear();
				}
			}
		}

		if(have == -1) {
			cout << 0 << nl;
			continue;
		}

		sort(put.begin(), put.end());
		put.resize(unique(put.begin(), put.end()) - put.begin());

		ll ans = power(p, have);
		for(int i : put) {
			ans += MOD - cur[i] * power(p, i) % MOD;
			cur[i] = 0;
		}
		cout << ans % MOD << nl;
	}

	return 0;
}