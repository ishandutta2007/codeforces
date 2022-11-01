#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		if ((n + m) % 2 == 0) {
			cout << "Tonya\n";
		} else {
			cout << "Burenka\n";
		}
	}
	return 0;
}