#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long power(long long a, long long b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

int main() {
	int n; cin >> n;
	cout << 6 * power(4, (1ll << n) - 2) % mod << endl;
	return 0;
}