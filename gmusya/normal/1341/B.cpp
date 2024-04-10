#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		vector <int> a(n), t(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 1; i < n - 1; i++)
			t[i] += (a[i] > a[i - 1] && a[i] > a[i + 1]);
		k -= 2;
		pair <int, int> ans = { 0, -1 };
		int sum = 0;
		for (int i = 1; i < k; i++)
			sum += t[i];
		for (int r = k; r < n; r++) {
			sum -= t[r - k];
			sum += t[r];
			ans = max(ans, { sum, - (r - k + 1) });
		}
		cout << ans.first + 1 << ' ' << -ans.second << '\n';
	}
	return 0;
}