#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector <int> a(3);
		cin >> a[0] >> a[1] >> a[2];
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		int ans = 0;
		int x = a[0] - a[1];
		ans += min(x, a[2]);
		a[0] -= min(x, a[2]);
		a[2] -= min(x, a[2]);
		if (a[2] == 0)
			ans += a[1];
		if (a[2] > 0)
			ans += (a[2] + a[1] + a[0]) / 2;
		cout << ans << endl;
	}
	return 0;
}