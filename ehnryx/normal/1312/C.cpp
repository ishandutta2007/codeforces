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



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		unordered_map<ll,int> cnt;
		for(int i=0; i<n; i++) {
			ll a;
			cin >> a;
			ll mk = 1;
			while(mk*k <= a) {
				mk *= k;
			}
			while(a > 0) {
				if(mk <= a) {
					cnt[mk]++;
					a -= mk;
				} else {
					mk /= k;
				}
			}
		}
		bool ok = true;
		for(auto [_, c] : cnt) {
			ok &= (c == 1);
		}
		if(ok) cout << "YES" << nl;
		else cout << "NO" << nl;
	}

	return 0;
}