// Who needs long templates? :)
//    ? :)

/*---------------------------------+
|      TEXHOKYOK 2017 OTOP 1     |
+----------------------------------+
|              3AAA B            |
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
	int n, m; cin >> n >> m; n--;
	vector<int> k(m), f(m);
	for (int i = 0; i < m; i++) {
		cin >> k[i] >> f[i]; k[i]--; f[i]--;
	}
	vector<int> can(10000, false);
	for (int i = 1; i < 256; i++) {
		bool ok = true;
		for (int j = 0; j < m; j++) {
			if (k[j] / i != f[j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			can[n / i] = true;
		}
	}
	vector<int> cans;
	for (int i = 0; i < (int)can.size(); i++) {
		if (can[i]) {
			cans.push_back(i+1);
		}
	}
	assert(cans.size() != 0);
	if (cans.size() == 1) {
		cout << cans[0] << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}