#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (b % a == 0)
		return a;
	return gcd(b % a, a);
}

int main() {
	int a, b, n;
	cin >> a >> b >> n;
	while (n > 0) {
		if (n -= gcd(a, n));
		if (n == 0) {
			cout << "0";
			return 0;
		}
		n -= gcd(b, n);
	}
	cout << "1";
	return 0;
}