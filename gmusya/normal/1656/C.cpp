#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		bool is_one = false;
		for (int i = 0; i < n; ++i) {
			if (a[i] == 1) {
				is_one = true;
			}
		}
		sort(a.begin(), a.end());
		bool can = true;
		for (int i = 0; i + 1 < n; ++i) {
			if (a[i] + 1 == a[i + 1]) {
				can = false;
			}
		}
		if (can || !is_one) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}