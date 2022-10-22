#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1 << 20 | 10];
int ans[1 << 20 | 10];
int f[1 << 20];

int Binom(int n, int k) {
	return (n & k) == k;
}

int Calc(int n, int k) {
	k = max(k, 0);
	int ans = f[n];
	for (int i = k; i < :: k; i++) {
		ans ^= Binom(n, i);
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = k; i < (1 << 20); i++) {
		f[i] = 1;
	}
	for (int j = 0; j < 20; j++) for (int i = 0; i < (1 << 20); i++) if (i >> j & 1) {
		f[i] ^= f[i ^ 1 << j];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = i + 1; j <= n; j++) {
			if (cnt > 30 || ((long long)a[i] << cnt) >= (1 << 20)) break;
			int e = a[i] << cnt;
			int len = j - i;
			ans[e] ^= Calc(n - 1 - len - 1 + (i == 0) + (j == n), k - (i != 0) - (j != n));
			if (j == n) break;
			cnt += a[j];
		}
	}
	int p = (1 << 20);
	while (p > 0 && !ans[p]) p--;
	while (p >= 0) printf("%d", ans[p]), p--;
	printf("\n");
	return 0;
}