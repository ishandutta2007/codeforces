#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		int x = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			x ^= a[i];
		}
		if (!x) {
			cout << "DRAW\n";
			continue;
		}
		int value = (1 << 30);
		while ((x & (value)) == 0)
			value /= 2;
		int cnt = 0;
		for (int i = 0; i < n; i++)
			cnt += ((a[i] & value) > 0);
		if (cnt == 1) {
			cout << "WIN\n";
			continue;
		}
		if (cnt % 4 == 1) {
			cout << "WIN\n";
			continue;
		}
		if (cnt % 4 == 3) {
			if (n % 2) cout << "LOSE\n";
			else cout << "WIN\n";
		}
	}
	return 0;
}