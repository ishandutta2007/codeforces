// Who needs long templates? :)
//    ? :)

/*---------------------------------+
|  Codeforces Round #423 (Div. 1)  |
+----------------------------------+
|             Problem B            |
+---------------------------------*/

#include <bits/stdc++.h>

using namespace std;

const int infinity = 1234567890;
const long double eps = 1e-8;

mt19937_64 randGen(chrono::system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	if (k == n-1) {
		cout << 2 << "\n";
		for (int i = 2; i <= n; i++) {
			cout << 1 << " " << i << "\n";
		}
		return 0;
	}
	if (k == n-2) {
		cout << 3 << "\n";
		cout << 1 << " " << 2 << "\n";
		cout << 1 << " " << 3 << "\n";
		cout << 2 << " " << 4 << "\n";
		for (int i = 5; i <= n; i++) {
			cout << 1 << " " << i << "\n";
		}
		return 0;
	}
	int free = n - k - 1;
	int busy = k;
	int ans = 2 * ( (free-1) / busy ) + 4;
	if (free % busy == 1) {
		ans--;
	}
	cout << ans << "\n";
	int vPtr = 1;
	for (int i = 0; i < busy; i++) {
		int prev = 1;
		int len = free / busy;
		if (i < free % busy) {
			len++;
		}
		for (int j = 0; j <= len; j++) {
			int nxt = ++vPtr;
			cout << prev << " " << nxt << "\n";
			prev = nxt;
		}
	}
	return 0;
}