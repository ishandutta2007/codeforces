#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 2 == 0) {
		int x = n / 2;
		if (x % 2 == 1)
			x++;
		cout << x << " " << n - x;
		return 0;
	}
	if (n % 3 == 0)
		cout << n - 6 << " " << 6;
	if (n % 3 == 1)
		cout << n - 4 << " " << 4;
	if (n % 3 == 2)
		cout << n - 8 << " " << 8;
	return 0;
}