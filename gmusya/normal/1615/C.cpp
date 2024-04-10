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
		vector<char> a(n), b(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
		}
		int cnt00 = 0, cnt01 = 0, cnt10 = 0, cnt11 = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == '0') {
				if (b[i] == '0') {
					++cnt00;
				} else {
					++cnt01;
				}
			} else {
				if (b[i] == '0') {
					++cnt10;
				} else {
					++cnt11;
				}
			}
		}
		int ans1 = n + 1;
		if ((cnt01 + cnt10) % 2 == 0) {
			if (cnt01 == cnt10) {
				ans1 = cnt01 + cnt10;
			}
		}
		int ans2 = n + 1;
		if ((cnt00 + cnt11) % 2 == 1) {
			if (cnt00 + 1 == cnt11) {
				ans2 = cnt00 + cnt11;
			}
		}
		int ans = min(ans1, ans2);
		if (ans == n + 1) {
			ans = -1;
		}
		cout << ans << '\n';
	}
	return 0;
}