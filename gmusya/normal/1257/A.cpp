#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		cout << min(n - 1, abs(b - a) + x) << endl;
	}
	return 0;
}