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
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		bool ok = true;
		if(x1 == x2) {
			ok &= (a+b == 0);
		}
		if(y1 == y2) {
			ok &= (c+d == 0);
		}
		ok &= (x-x1 >= a-b);
		ok &= (x2-x >= b-a);
		ok &= (y-y1 >= c-d);
		ok &= (y2-y >= d-c);
		if(ok) {
			cout << "YES" << nl;
		} else {
			cout << "NO" << nl;
		}
	}

	return 0;
}