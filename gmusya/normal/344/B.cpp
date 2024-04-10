#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((a + b + c) % 2 != 0 || 2 * max(a, max(b, c)) > (a + b + c)) {
		cout << "Impossible";
		return 0;
	}
	int x = (a + b + c) / 2 - c;
	int y = (a + b + c) / 2 - a;
	int z = (a + b + c) / 2 - b;
	if (x < 0 || y < 0 || z < 0) {
		cout << "Impossible";
		return 0;
	}
	cout << x << " " << y << " " << z;
	return 0;
}