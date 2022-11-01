#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	while (k > n % 10) {
		k -= (n % 10 + 1);
		n /= 10;
	}
	cout << n - k;
	return 0;
}