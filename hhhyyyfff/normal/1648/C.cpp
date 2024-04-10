#include <bits/stdc++.h>

using namespace std;
#define MOD 998244353

int n, m, s, ans, t[200000], cnt[200001], presums[200001], c[200001];
long long mul = 1, inv[200001], frac[200001];

void upd(int x) {
	while (x <= 200000) {
		++c[x];
		x += x & -x;
	}
}

int qry(int x) {
	int ret = 0;
	while (x) {
		ret += c[x];
		x -= x & -x;
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	frac[0] = frac[1] = inv[1] = 1;
	for (int i = 2; i <= 200000; ++i) {
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
		frac[i] = frac[i - 1] * i % MOD;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &s);
		mul = mul * inv[++cnt[s]] % MOD;
	}
	for (int i = 1; i <= 200000; ++i) presums[i] = presums[i - 1] + cnt[i];
	for (int i = 0; i < m; ++i) {
		scanf("%d", &t[i]);
		if (presums[t[i] - 1] - qry(t[i] - 1)) {
			ans = (ans + (frac[n - i] - frac[n - i - 1] *
					(n - i - (presums[t[i] - 1] - qry(t[i] - 1)))) % MOD * mul) % MOD;
		}
		if (!cnt[t[i]]) {
			if (n == i) ans = (ans + 1) % MOD;
			break;
		}
		mul = (mul * cnt[t[i]]--) % MOD;
		upd(t[i]);
	}
	printf("%d\n", (ans + MOD) % MOD);
	return 0;
}