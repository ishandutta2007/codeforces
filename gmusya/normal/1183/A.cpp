#include <iostream>
#include <vector>

using namespace std;

int sumofdigits(int a) {
	int sum = 0;
	while (a > 0) {
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	while (sumofdigits(n) % 4 != 0) {
		n++;
	}
	cout << n;
	return 0;
}