#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 2 == 0) {
		while (n > 2) {
			cout << "I hate that I love that ";
			n -= 2;
		}
		cout << "I hate that I love it";
	}
	else {
		while (n > 1) {
			cout << "I hate that I love that ";
				n -= 2;
		}
		cout << "I hate it";
	}
	return 0;
}