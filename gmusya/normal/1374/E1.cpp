#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector <int> t(n), a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> t[i] >> a[i] >> b[i];
	vector <int> x11, x01, x10;
	for (int i = 0; i < n; i++) {
		if (a[i] && b[i]) x11.push_back(t[i]);
		if (a[i] && !b[i]) x10.push_back(t[i]);
		if (!a[i] && b[i]) x01.push_back(t[i]);
	}
	sort(x11.begin(), x11.end());
	sort(x10.begin(), x10.end());
	sort(x01.begin(), x01.end());
	int it0 = 0, it1 = 0;
	int s0 = x11.size(), s1 = min(x10.size(), x01.size());
	if (s0 + s1 < k) {
		cout << -1;
		return 0;
	}
	int ans = 0;
	while (it0 + it1 < k) {
		if (it0 == s0) {
			ans += x01[it1];
			ans += x10[it1];
			it1++;
			continue;
		}
		if (it1 == s1) {
			ans += x11[it0];
			it0++;
			continue;
		}
		int var1 = x01[it1] + x10[it1];
		int var2 = x11[it0];
		if (var1 < var2) {
			ans += var1;
			it1++;
			continue;
		}
		ans += var2;
		it0++;
	}
	cout << ans;
	return 0;
}