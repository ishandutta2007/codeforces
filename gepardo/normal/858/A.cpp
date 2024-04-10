// Who needs long templates? :)
//    ? :)

/*---------------------------------+
|      TEXHOKYOK 2017 OTOP 1     |
+----------------------------------+
|              3AAA A            |
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
	int64_t n, k; cin >> n >> k;
	int64_t d2 = 0, d5 = 0;
	while (n % 2 == 0) {
		d2++;
		n /= 2;
	}
	while (n % 5 == 0) {
		d5++;
		n /= 5;
	}
	d2 = max(d2, k);
	d5 = max(d5, k);
	for (int i = 0; i < d2; i++) {
		n *= 2;
	}
	for (int i = 0; i < d5; i++) {
		n *= 5;
	}
	cout << n << endl;
	return 0;
}