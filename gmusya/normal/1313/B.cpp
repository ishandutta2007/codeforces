#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;
		cout << max(1, min(n, x + y - n + 1)) << ' ' << min(n, x + y - 1) << '\n';
	}
	return 0;
}