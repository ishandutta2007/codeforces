#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long a, b, c;
		cin >> a >> c >> b;
		if (a < b) cout << 1 << ' ';
		else cout << "-1 ";
		if (b < a * c) cout << c << ' ';
		else cout << "-1 ";
		cout << '\n';
	}
	return 0;
}