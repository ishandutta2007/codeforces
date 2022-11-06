#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int M = 998244353;

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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	int c01 = 0, c10 = 0, len0 = 0, len1 = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] == 0) {
			++len0;
		} else {
			++len1;
		}
		if (a[i] == 0 && b[i] == 1) {
			++c10;
		}
		if (a[i] == 1 && b[i] == 0) {
			++c01;
		}
	}
	int pairall = n * (n - 1ll) / 2 % M, ans = 0;
	while (c10 && c01) {
		int x = 1ll * qpw(1ll * c10 * c01 % M, -1) * pairall % M;
		ans = (ans + x) % M;
		--c10, --c01;
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