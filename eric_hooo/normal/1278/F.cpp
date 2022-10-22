#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long power(int a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

long long s[5010];

int main() {
	int n, m, k; cin >> n >> m >> k;
	if (m == 1) {
		cout << power(n, k) << endl;
		return 0;
	}
	s[1] = 1;
	for (int i = 2; i <= k; i++) {
		for (int j = k; j >= 1; j--) {
			s[j] = (s[j] * j + s[j - 1]) % mod;
		}
	}
	long long dw = 1, ans = 0, V = power(m, mod - 2), pw = 1;
	for (int i = 1; i <= k; i++) {
		dw = dw * (n - i + 1) % mod, pw = pw * V % mod;
		ans = (ans + s[i] * dw % mod * pw) % mod;
	}
	cout << ans << endl;
	return 0;
}