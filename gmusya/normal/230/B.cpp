#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		long long x;
		cin >> x;
		if (x == 1) {
			cout << "NO\n";
			continue;
		}
		long long q = sqrt(x);
		if (q * q != x) {
			cout << "NO\n";
			continue;
		}
		long long i = 2;
		while (q % i != 0 && i * i <= q) {
			++i;
		}
		if (i * i > q) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}

/*
 n = p^2
 */