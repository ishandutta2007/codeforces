#include <iostream>

using namespace std;

int gcd(int a, int b) {
	for (int i = 100; i > 1; i--) {
		if (a % i == 0 && b % i == 0) return i;
	}
	
	return 1;
}

int main() {
	int a, b, n;
	cin >> a >> b >> n;
	

	
	while (true) {
		int aTake = gcd(a, n);
		n -= aTake;
		if (n < 0) {
			cout << "1" << endl;
			break;
		}
		
		int bTake = gcd(b, n);
		n -= bTake;
		if (n < 0) {
			cout << "0" << endl;
			break;
		}
	}
	
	return 0;
}