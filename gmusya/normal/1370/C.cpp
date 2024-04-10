#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << "FastestFinger\n";
			continue;
		}
		if (n % 2) {
			cout << "Ashishgup\n";
			continue;
		}
		int x = 2;
		int even = 0;
		while (n % x == 0) {
			x *= 2;
			even++;
		}
		int odd = 0;
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0 && ((n / i) % 2 || i % 2))
				odd++;
		if (!odd) {
			if (even != 1) cout << "FastestFinger\n";
			else cout << "Ashishgup\n";
			continue;
		}
		if (odd == 1 && even == 1) cout << "FastestFinger\n";
		else cout << "Ashishgup\n";
	}
	return 0;
}