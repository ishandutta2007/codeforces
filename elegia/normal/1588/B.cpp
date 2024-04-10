#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll query(int l, int r) {
	cout << "? " << l << ' ' << r << endl;
	ll ret; cin >> ret; return ret;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		int low = 1, high = n;
		ll val = query(1, n);
		while (low < high) {
			int mid = (low + high) / 2;
			if (query(1, mid) < val) low = mid + 1;
			else high = mid;
		}
		int C = high, B = C + query(1, C - 1) - val, A = B - 1 + query(1, B - 2) - query(1, B - 1);
		cout << "! " << A << ' ' << B << ' ' << C << endl;
	}

	return 0;
}