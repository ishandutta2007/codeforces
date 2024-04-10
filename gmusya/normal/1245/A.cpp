#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int a, b, t;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		int n = gcd(a, b);
		if (n == 1)
			cout << "Finite" << endl;
		else
			cout << "Infinite" << endl;
	}
	return 0;
}