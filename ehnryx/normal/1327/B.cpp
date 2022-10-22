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
		int n;
		cin >> n;
		vector<bool> taken(n);
		int rem = 0;
		for(int i=0; i<n; i++) {
			int m;
			cin >> m;
			bool ok = false;
			for(int j=0; j<m; j++) {
				int v;
				cin >> v;
				--v;
				if(!ok && !taken[v]) {
					taken[v] = true;
					ok = true;
				}
			}
			if(!ok) {
				rem = i+1;
			}
		}
		if(rem == 0) {
			cout << "OPTIMAL" << nl;
		} else {
			int ans = 0;
			for(int i=0; i<n; i++) {
				if(!taken[i]) {
					ans = i+1;
				}
			}
			assert(ans);
			cout << "IMPROVE" << nl;
			cout << rem << " " << ans << nl;
		}
	}

	return 0;
}