#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, n, m;
		cin >> x >> n >> m;
		while (x > 20 && n) {
			x = (x / 2) + 10;
			n--;
		}
		if (m * 10 >= x) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}