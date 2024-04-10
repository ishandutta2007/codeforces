#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int c = max(max(a, b), 2 * min(a, b));
		cout << c * c << '\n';
	}
	return 0;
}