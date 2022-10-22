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

	int n;
	cin >> n;
	ll a[n];
	int ans = 0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		ans += a[i] % 2;
	}

	//while(clock() < 2*CLOCKS_PER_SEC) {
	for(int tt=0; tt<9; tt++) {
		int s = rng()%n;
		for(int j=-1; j<=1; j++) {
			ll v = a[s] + j;
			if(v <= 1) continue;
			vector<ll> primes;
			for(ll p=2; p*p<=v; p++) {
				if(v%p == 0) {
					while(v%p == 0) {
						v /= p;
					}
					primes.push_back(p);
				}
			}
			if(v > 1) {
				primes.push_back(v);
			}

			for(ll p : primes) {
				ll cur = 0;
				for(int i=0; i<n && cur < ans; i++) {
					ll lb = a[i] / p * p;
					ll ub = lb + p;
					ll dist = ub - a[i];
					if(lb > 0) dist = min(dist, a[i] - lb);
					cur += dist;
				}
				ans = min((ll)ans, cur);
			}
		}
	}

	cout << ans << nl;

	return 0;
}