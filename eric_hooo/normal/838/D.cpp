#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long power(int a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

int main() {
	int n, m; cin >> n >> m;
	cout << power(2 * (n + 1), m) * (n + 1 - m) % mod * power(n + 1, mod - 2) % mod << endl;
	return 0;
}