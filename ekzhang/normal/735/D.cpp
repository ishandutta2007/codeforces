#include <bits/stdc++.h>
using namespace std;

int N;

bool is_prime(int k) {
	if (k == 1) return false;
	for (int x = 2; x < sqrt(k) + .01; x++) {
		if (k % x == 0) {
			return false;
		}
	}
	return true;
}

int solve(int n) {
	if (is_prime(n)) {
		return 1;
	}
	if (n % 2 == 0) {
		return 2;
	}
	if (is_prime(n-2)) {
		return 2;
	}
	return 3;
}

int main() {
	// freopen("input.txt", "r", stdin);
	cin >> N;
	cout << solve(N) << endl;
}