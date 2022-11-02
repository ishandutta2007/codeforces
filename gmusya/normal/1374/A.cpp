#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y, n;
		cin >> x >> y >> n;
		int k = n;
		int r = k % x;
		int dis;
		if (r >= y) dis = r - y;
		else dis = x + (r - y);
		cout << k - dis << '\n';
	}
	return 0;
}