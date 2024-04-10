#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n >= 0) {
		cout << n;
		return 0;
	}
	n = -n;
	if (n / 10 % 10 > n % 10)
		cout << -(n / 100 * 10 + n % 10);
	else
		cout << -(n / 10);
	return 0;
}