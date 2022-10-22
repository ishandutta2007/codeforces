#include <bits/stdc++.h>
using namespace std;

int maxj[1000010];

int main () {
	int T; cin >> T;
	while (T--) {
		long long p, f; cin >> p >> f;
		long long c1, c2; cin >> c1 >> c2;
		long long w1, w2; cin >> w1 >> w2;
		if (w1 > w2) swap(w1, w2), swap(c1, c2);
		int l = 0, r = c1 + c2;
		while (l < r) {
			long long mid = l + r + 1 >> 1;
			bool ok = 0;
			for (int i = 0; i <= c1; i++) {
				if (i > mid) break;
				if (i * w1 > p) break;
				long long nc1 = c1 - i, nc2 = c2 - (p - i * w1) / w2;
				long long nmid = mid - (c1 + c2 - nc1 - nc2);
				if (nc1 * w1 > f) {
					if (f / w1 >= nmid) ok = 1;
				} else {
					if (nc1 + min((f - nc1 * w1) / w2, nc2) >= nmid) ok = 1;
				}
			}
			if (ok) l = mid;
			else r = mid - 1;
		}
		cout << l << endl;
	}
	return 0;
}