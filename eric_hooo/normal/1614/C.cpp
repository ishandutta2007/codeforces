#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int n, m;
int L[200010], R[200010], X[200010];
int cnt[200010];
int a[200010];
long long pw[200010];

int Solve(int it) {
	for (int i = 0; i <= n + 1; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int l = L[i], r = R[i], x = X[i] >> it & 1;
		if (x == 0) cnt[l]++, cnt[r + 1]--;
	}
	for (int i = 1; i <= n; i++) {
		cnt[i] += cnt[i - 1];
	}
	int p = 0, q = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i]) p++;
		else q++;
	}
	if (!q) return 0;
	return (1ll * pw[q - 1] * pw[p] % mod << it) % mod;
}

void Main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &L[i], &R[i], &X[i]);
	}
	int ans = 0;
	for (int it = 0; it < 30; it++) {
		ans = (ans + Solve(it)) % mod;
	}
	printf("%d\n", ans);
}

int main() {
	pw[0] = 1; for (int i = 1; i <= 200005; i++) pw[i] = pw[i - 1] * 2 % mod;
	int T; scanf("%d", &T);
	while (T--) Main();
	return 0;
}