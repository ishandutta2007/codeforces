#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector <int> p2(31);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int p = 2;
		while (p * 2 - 1 <= n) {
			p *= 2;
			if (n % (p - 1) == 0) {
				cout << n / (p - 1) << endl;
				break;
			}
		}
	}
	return 0;
}