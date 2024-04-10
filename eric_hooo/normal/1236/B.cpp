#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long power(long long a, long long b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

int main () {
	int n, m; cin >> n >> m;
	cout << power(power(2, m) - 1, n) << endl;
	return 0;
}