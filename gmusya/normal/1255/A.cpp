#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		int a, b;
		cin >> a >> b;
		int k = abs(a - b);
		cout << (k / 5) + (k - (k / 5 * 5)) / 2 + (k - (((k / 5) * 5) + (k - (k / 5 * 5)) / 2 * 2)) << endl;
	}
	return 0;
}