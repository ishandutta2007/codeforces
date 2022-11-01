#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long t;
	cin >> t;
	while (t--) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a <= b) {
			cout << b << '\n';
			continue;
		}
		if (d >= c) {
			cout << -1 << '\n';
			continue;
		}
		long long x = a - b;
		long long l = c - d;
		long long num = (x + l - 1) / l;
		cout << b + num * c << '\n';
	}
	return 0;
}