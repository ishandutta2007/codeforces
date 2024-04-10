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

	int T;
	cin >> T;
	while(T--) {
		int h, c, t;
		cin >> h >> c >> t;
		int d = 2 * (h-c);
		int g = 2 * (t-c);
		if(g <= d/2) {
			cout << 2 << nl;
		} else {
			int l = 1;
			int r = 1e9;
			while(l < r) {
				int m = (l+r+1) / 2;
				ll top = (ll) m*d;
				ll bot = 2*m - 1;
				if(top >= bot * g) {
					l = m;
				} else {
					r = m-1;
				}
			}
			ld first = (ld)r*d / (2*r-1);
			ld second = (ld)(r+1)*d / (2*r+1);
			assert(first >= g && g > second);
			if(abs(first - g) <= abs(second - g)) {
				cout << 2*r-1 << nl;
			} else {
				cout << 2*r+1 << nl;
			}
		}
	}

	return 0;
}