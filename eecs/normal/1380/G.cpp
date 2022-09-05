#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010, P = 998244353;
int n, a[maxn], s[maxn];

int qp(int x, int y) {
	int z = 1;
	for (; y; y >>= 1, x = 1LL * x * x % P) {
		if (y & 1) z = 1LL * z * x % P;
	}
	return z;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; i++) {
		s[i] = (s[i - 1] + a[i]) % P;
	}
	int inv = qp(n, P - 2);
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 0, k = 0; k < n; j++, k += i) {
			ans = (ans + 1LL * j * (s[min(n, k + i)] - s[k] + P)) % P;
		}
		printf("%lld ", 1LL * ans * inv % P);
	}
	return 0;
}