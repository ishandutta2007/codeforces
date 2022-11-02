#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		if (2 * l > r) {
			cout << -1 << ' ' << -1 << '\n';
			continue;
		}
		cout << l << ' ' << 2 * l << '\n';
	}
	return 0;
}