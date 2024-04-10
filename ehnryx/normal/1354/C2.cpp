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

#undef M_PIl
const ld M_PIl = acos(-1.L);

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
//#define EVEN
#ifdef EVEN
		ld h = (ld)1/2 / tan(M_PIl/(2*n));
		cout << 2*h << nl;
#else
		ld r = (ld)1/2 / sin(M_PIl/(2*n));
		pt diag = pt(1, 1) / sqrt(2.L) * r;
		pt step = exp(pt(0, M_PIl/n));
		ld h = diag.imag();
		for(int i=0; i<n; i++) {
			diag *= step;
			h = max(h, diag.imag());
		}
		cout << 2*h << nl;
#endif
	}

	return 0;
}