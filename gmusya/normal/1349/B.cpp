#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector <int> a(n);
		bool tf = false;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == k)
				tf = true;
		}
		if (!tf) {
			cout << "no\n";
			continue;
		}
		if (n == 1) {
			cout << "yes\n";
			continue;
		}
		tf = false;
		for (int it = 1; it < 32; it++) {
			int sz = (1 << it);
			if (sz > n) break;
			int bal = 0;
			for (int i = 0; i < sz; i++) {
				if (a[i] >= k) bal++;
				else bal--;
			}
			if (bal > 0) {
				tf = true;
				break;
			}
			for (int j = sz; j < n; j++) {
				if (a[j] >= k) bal++;
				else bal--;
				if (bal > 0) {
					tf = true;
					break;
				}
				if (a[j - sz] >= k) bal--;
				else bal++;
				if (bal > 0) {
					tf = true;
					break;
				}
			}
		}
		if (tf) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}