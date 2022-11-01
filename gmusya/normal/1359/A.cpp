#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		int cards = n / k;
		if (m <= cards) {
			cout << m << '\n';
			continue;
		}
		m -= cards;
		for (int i = 1; i <= 100; i++) 
			if (i * (k - 1) >= m) {
				cout << cards - i << '\n';
				break;
			}

	}
	return 0;
}