#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x, m;
		cin >> n >> x >> m;
		int l = x, r = x;
		while (m--) {
			int L, R;
			cin >> L >> R;
			if (L > r || R < l) continue;
			l = min(L, l);
			r = max(R, r);
		}
		cout << r - l + 1 << '\n';
	}
	return 0;
}