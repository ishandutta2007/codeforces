#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		k++;
		vector <int> u;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			if (c == '1') u.push_back(i);
		}
		if (u.size() == 0) {
			cout << (n + k - 1) / k << '\n';
			continue;
		}
		int pre = u[0] - (k - 1);
		int suf = n - u[u.size() - 1] - 1 - (k - 1);
		int ans = 0;
		ans += max(0, (pre + k - 1) / k);
		ans += max(0, (suf + k - 1) / k);
		for (int i = 0; i + 1 < u.size(); i++) {
			int l = u[i];
			int r = u[i + 1];
			int length = u[i + 1] - u[i] - 1 - 2 * (k - 1);
			ans += (length + k - 1) / k;
		}
		cout << ans << '\n';
	}
	return 0;
}