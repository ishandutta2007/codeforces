#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int rep = 0; rep != n; ++rep) {
			int ig; cin >> ig;
		}
		cout << n * 3 << '\n';
		for (int i = 1; i <= n; i += 2) {
			cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
			cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
			cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
			cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
			cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
			cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
		}
	}
	return 0;
}