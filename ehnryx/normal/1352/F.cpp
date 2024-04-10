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
		int a, b, c;
		cin >> a >> c >> b;
		if(b == 0 && c == 0) {
			for(int i=0; i<=a; i++) {
				cout << '0';
			}
			cout << nl;
		} else if(a == 0 && c == 0) {
			for(int i=0; i<=b; i++) {
				cout << '1';
			}
			cout << nl;
		} else {
			assert(c > 0);
			for(int i=0; i<=a; i++) {
				cout << '0';
			}
			for(int i=0; i<=b; i++) {
				cout << '1';
			}
			c--;
			for(int i=0; i<c; i++) {
				cout << (i%2 ? '1' : '0');
			}
			cout << nl;
		}
	}

	return 0;
}