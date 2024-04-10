#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n < 4) {
			cout << -1 << '\n';
			continue;
		}
		if (n == 4) {
			cout << "3 1 4 2 \n";
			continue;
		}
		for (int i = 1; i <= n; i += 2)
			cout << i << ' ';
		if (n % 2) {
			cout << n - 3 << ' ' << n - 1 << ' ';
			for (int i = n - 5; i >= 1; i -= 2)
				cout << i << ' ';
			cout << '\n';
			continue;
		}
		cout << n - 4 << ' ' << n << ' ' << n - 2 << ' ';
		for (int i = n - 6; i >= 1; i -= 2)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}