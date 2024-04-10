// Who needs long templates? :)
//    ? :)

/*---------------------------------+
|  CodeForces Round #440 (Div. 1)  |
+----------------------------------+
|             Problem A            |
+---------------------------------*/

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

const int infinity = 1234567890;
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

signed main() {
	ios_base::sync_with_stdio(false);
	vector<int> v(1000000, -12345678);
	v[0] = 0;
	for (int i = 4; i < (int)v.size(); i++) {
		if (i >= 4) {
			v[i] = max(v[i], v[i-4]+1);
		}
		if (i >= 6) {
			v[i] = max(v[i], v[i-6]+1);
		}
		if (i >= 9) {
			v[i] = max(v[i], v[i-9]+1);
		}
	}
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int q; cin >> q;
		if (q < 1000) {
			cout << ((v[q] < 0) ? -1 : v[q]) << "\n";
		} else {
			int ans = q / 4;
			if (q & 1) {
				ans--;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}