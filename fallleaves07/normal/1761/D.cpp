#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 1e9 + 7;

int qpw(int a, int b) {
	a %= M;
	if (b < 0) {
		(b %= M - 1) += M - 1;
	}
	int c = 1;
	for (; b; b >>= 1, a = 1ll * a * a % M) {
		if (b & 1) {
			c = 1ll * c * a % M;
		}
	}
	return c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> fct(n + 1), ifc(n + 1), pw3(n + 1), pw2(n + 1);
	fct[0] = pw3[0] = pw2[0] = 1;
	for (int i = 1; i <= n; i++) {
		fct[i] = 1ll * fct[i - 1] * i % M;
		pw3[i] = 3ll * pw3[i - 1] % M;
		pw2[i] = 2ll * pw2[i - 1] % M;
	}
	ifc[n] = qpw(fct[n], -1);
	for (int i = n - 1; i >= 0; i--) {
		ifc[i] = ifc[i + 1] * (i + 1ll) % M;
	}
	auto C = [&](int n, int m) -> int {
		if (n < m) {
			return 0;
		}
		return 1ll * fct[n] * ifc[m] % M * ifc[n - m] % M;
	};
	int m = n + 1 - k, ans = 0;
	if (k == 0) {
		ans = pw3[m - 1];
	}
	for (int i = 1; i <= k; i++) {
		int c1 = 1ll * C(m - 1, i) * C(k - 1, i - 1) % M;
		int c00 = m - 1 - i, c11 = k - 1 - (i - 1);
		if (c1 > 0) {
			ans = (ans + 1ll * c1 * pw3[c00] % M * pw3[c11]) % M;
		}

		int c2 = 1ll * C(m - 1, i - 1) * C(k - 1, i - 1) % M;
		c00 = m - 1 - (i - 1), c11 = k - 1 - (i - 1);
		if (c2 > 0) {
			ans = (ans + 1ll * c2 * pw3[c00] % M * pw3[c11]) % M;
		}
	}
	printf("%d\n", (ans % M + M) % M);
	return 0;
}