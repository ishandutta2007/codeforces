#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int ang;
		cin >> ang;
		int g = gcd(ang, 180);
		int cnt = ang / g;
		int n = 180 / g;
		if (cnt + 1 == n) cout << n * 2 << endl;
		else cout << n << endl;
	}
	return 0;
}