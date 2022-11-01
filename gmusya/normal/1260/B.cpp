#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int x = 0; x < t; x++) {
		int a, b;
		cin >> a >> b;
		if ((a + b) % 3 == 0 && a <= 2 * b && b <= 2 * a)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}