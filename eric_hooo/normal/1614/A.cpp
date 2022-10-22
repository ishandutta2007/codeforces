#include <bits/stdc++.h>
using namespace std;

vector <int> a;

int main() {
	int T; cin >> T;
	while (T--) {
		a.clear();
		int n, l, r, k; cin >> n >> l >> r >> k;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (x >= l && x <= r) a.push_back(x);
		}
		sort(a.begin(), a.end());
		int pos = 0;
		while (pos < a.size() && k >= a[pos]) k -= a[pos], pos++;
		cout << pos << endl;
	}
	return 0;
}