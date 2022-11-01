#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int ans = 0;
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector <int> m(n);
		m[0] = a[0];
		for (int i = 1; i < n; i++) {
			m[i] = max(m[i - 1], a[i]);
			int diff = m[i] - a[i];
			int x = 0;
			while (diff) {
				x++;
				diff /= 2;
			}
			ans = max(x, ans);
		}
		cout << ans << '\n';
	}
	return 0;
}