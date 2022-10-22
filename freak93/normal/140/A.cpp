#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double n, R, r; cin >> n >> R >> r;

	if (n == 1 && r <= R) {
		cout << "YES";
		return 0;
	}

	if (r * 2 > R) {
		cout << "NO";
		return 0;
	}

	//cerr << 2.0 * (R - r) * sin(M_PI / n);
	if (2.0 * (R - r) * sin(M_PI / n) + (1e-9) >= 2.0 * r)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}