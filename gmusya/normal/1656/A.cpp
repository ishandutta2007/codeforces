#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>

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
		int min_pos = min_element(a.begin(), a.end()) - a.begin();
		int max_pos = max_element(a.begin(), a.end()) - a.begin();
		cout << min_pos + 1 << ' ' << max_pos + 1 << '\n';
	}
	return 0;
}