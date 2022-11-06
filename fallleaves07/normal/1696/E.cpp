#include<bits/stdc++.h>
using namespace std;
using LL = long long;
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
	int n;
	cin >> n;
	const int N = 4e5;
	vector<int> fct(N + 1), ifc(N + 1);
	fct[0] = 1;
	for (int i = 1; i <= N; i++) {
		fct[i] = 1ll * fct[i - 1] * i % M;
	}
	ifc[N] = qpw(fct[N], -1);
	for (int i = N - 1; i >= 0; i--) {
		ifc[i] = ifc[i + 1] * (i + 1ll) % M;
	}
	auto C = [&](int n, int m) -> int {
		if (n < 0 || m < 0 || n - m < 0) {
			return 0;
		}
		return 1ll * fct[n] * ifc[m] % M * ifc[n - m] % M;
	};
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		int a;
		cin >> a;
		if (a > 0) {
			ans = (ans + C(i + a, i + 1)) % M;
		}
	}
	printf("%d\n", (ans % M + M) % M);
    return 0;
}