#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		if (n > 40) {
			a.resize(40);
			n = 40;
		}
		while (!a.empty()) {
			bool deleted = false;
			for (int i = n - 1; i >= 0 && !deleted; --i) {
				if (a[i] % (i + 2)) {
					a.erase(a.begin() + i);
					deleted = true;
				}
			}
			n = static_cast<int>(a.size());
			if (!deleted) {
				break;
			}
		}
		if (a.empty()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}