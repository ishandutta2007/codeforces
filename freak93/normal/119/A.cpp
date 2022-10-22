#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	int a, b, n;
	cin >> a >> b >> n;
	int rez = 1;
	while (n > 0)
		n -= gcd(a, n), swap(a, b), ++rez;
	
	cout << rez % 2;
}