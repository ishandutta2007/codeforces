#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += a[i];
		if (sum % x) {
			cout << n << '\n';
			continue;
		}
		int l = 0, r = n - 1;
		while (l < n && a[l] % x == 0) l++;
		while (r >= 0 && a[r] % x == 0) r--;
		if (l == n) {
			cout << -1 << '\n';
			continue;
		}
		int ans = min(l + 1, n - r);
		cout << n - ans << '\n';
	}
	return 0;
}