#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x, y;
		cin >> x >> y;
		if ((x == 1 && y == 1) || (x == 2 && y <= 3) || (x == 3 && y <= 3) || x >= 4)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}