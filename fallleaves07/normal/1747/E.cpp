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

void solve() {
	int n, m;
	cin >> n >> m;
	int mx = (n + m + 1) * 2;
	vector<int> fct(mx + 1), ifc(mx + 1);
	fct[0] = 1;
	for (int i = 1; i <= mx; i++) {
		fct[i] = 1ll * fct[i - 1] * i % M;
	}
	ifc[mx] = qpw(fct[mx], -1);
	for (int i = mx - 1; i >= 0; i--) {
		ifc[i] = ifc[i + 1] * (i + 1ll) % M;
	}
	auto C = [&](int n, int m) -> int {
		return 1ll * fct[n] * ifc[m] % M * ifc[n - m] % M;
	};
	auto getsgn = [](int x) {
		return (x % 2 == 0) ? 1 : -1;
	};
	int ans = 0, sum = 0;
	for (int j = 0, sgn = 1; (n + m - 1) + j <= n + m - 1; j++, sgn = -sgn) {
		sum = (sum + 1ll * C((n + m - 1) + j + 2, j) * sgn) % M;
	}
	for (int i = n + m - 1; i >= 0; i--) {
		int x = 1ll * C(n + i, i) * C(m + i, i) % M;
		ans = (ans + 1ll * x * sum % M * (i + 2ll)) % M;
		sum = (sum * 2ll - C(i + 2, 0) - 1ll * getsgn(n + m - i - 1) * C(n + m + 1, n + m - i - 1)) % M;
		sum = (sum + C(i + 1, 0) + 1ll * getsgn(n + m - i) * C(n + m + 1, n + m - i)) % M;
	}
	printf("%d\n", (ans % M + M) % M);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}