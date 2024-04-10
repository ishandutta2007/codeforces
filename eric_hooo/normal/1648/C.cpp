#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

long long power(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

namespace BIT {
	int T[200010];
	void Modify(int x, int v) {
		while (x <= 200005) ADD(T[x], v), x += x & -x;
	}
	int Query(int x) {
		int res = 0;
		while (x) ADD(res, T[x]), x -= x & -x;
		return res;
	}
	int Query(int l, int r) {return (Query(r) - Query(l - 1) + mod) % mod;}
}

int n, m;
int a[200010], b[200010];
long long fac[200010], inv[200010];
int cnt[200010];

int main() {
	fac[0] = 1; for (int i = 1; i <= 200005; i++) fac[i] = fac[i - 1] * i % mod;
	inv[200005] = power(fac[200005], mod - 2); for (int i = 200004; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int j = 1; j <= m; j++) {
		scanf("%d", &b[j]);
	}
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
	}
	long long ans = 0, coef = 1;
	for (int i = 1; i <= 200000; i++) {
		coef = coef * inv[cnt[i]] % mod;
		BIT :: Modify(i, cnt[i]);
	}
	int tot = n;
	for (int j = 1; j <= m; j++) {
		tot--;
		int x = b[j];
		ans = (ans + BIT :: Query(x - 1) * coef % mod * fac[tot]) % mod;
		if (!cnt[x]) break;
		coef = coef * cnt[x] % mod, cnt[x]--;
		BIT :: Modify(x, -1);
	}
	if (tot < 0) ans = (ans + 1) % mod;
	printf("%lld\n", ans);
	return 0;
}