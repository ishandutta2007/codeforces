#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		k %= 4;
		if (k == 0) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			if (k % 2 == 1) {
				for (int i = 1; i <= n; i += 2) {
					cout << i << ' ' << i + 1 << '\n';
				}
			} else {
				for (int i = 1; i <= n; i += 2) {
					if ((i + 1) % 4 == 2) {
						cout << i + 1 << ' ' << i << '\n';
					} else {
						cout << i << ' ' << i + 1 << '\n';
					}
				}
			}
		}
	}
	return 0;
}