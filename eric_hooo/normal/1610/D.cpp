#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int n;
int a[100];
long long pw[200010];

int main() {
	pw[0] = 1; for (int i = 1; i <= 200005; i++) pw[i] = pw[i - 1] * 2 % mod;
	scanf("%d", &n);
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = ans * 2 % mod;
	}
	SUB(ans, 1);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		int k = 0;
		while (!(x & 1)) x >>= 1, k++;
		a[k]++;
	}
	for (int i = 1; i <= 30; i++) {
		int cur = a[i], nxt = 0;
		for (int j = i + 1; j <= 30; j++) {
			nxt += a[j];
		}
		if (cur) SUB(ans, pw[nxt] * pw[cur - 1] % mod);
	}
	printf("%d\n", ans);
	return 0;
}