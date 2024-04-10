#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

long long dp[17][100010];
long long coef[100010];

long long Calc(int l, int r) {
	long long sum = 0;
	for (int i = l; i <= r; ) {
		int v = r / i, j = r / v;
		sum += coef[v] * (j - i + 1ll);
		i = j + 1;
	}
	return sum;
}

void Solve(long long *f, long long *g, int l, int r, int L, int R) {
	if (l > r) return ;
	int mid = l + r >> 1, pos = -1;
	if (min(mid - 1, R) >= L) {
		long long wei = Calc(min(mid - 1, R) + 1, mid);
		for (int i = min(mid - 1, R); i >= L; i--) {
			if (g[mid] > f[i] + wei) g[mid] = f[i] + wei, pos = i;
			wei += coef[mid / i];
		}
	}
	if (pos == -1) pos = L;
	Solve(f, g, l, mid - 1, L, pos);
	Solve(f, g, mid + 1, r, pos, R);
}

int main() {
	for (int i = 1; i <= N; i++) {
		coef[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + i; j <= N; j += i) {
			coef[j] -= coef[i];
		}
	}
	for (int i = 1; i <= N; i++) {
		coef[i] += coef[i - 1];
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		dp[1][i] = i * (i + 1ll) / 2;
	}
	for (int it = 1; it < 16; it++) {
		Solve(dp[it], dp[it + 1], 1, N, 1, N);
	}
	int q; scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int n, k; scanf("%d%d", &n, &k);
		if (k >= 17) printf("%d\n", n);
		else printf("%lld\n", dp[k][n]);
	}
	return 0;
}