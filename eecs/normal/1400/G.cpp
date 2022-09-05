#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010, P = 998244353;
int n, m, ans, fact[maxn], finv[maxn], inv[maxn], c[maxn];
int l[maxn], r[maxn], cnt[maxn], a[maxn], b[maxn], s[maxn][45];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int binom(int n, int m) {
	if (n < m || m < 0) return 0;
	return 1LL * fact[n] * finv[m] % P * finv[n - m] % P;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = finv[0] = inv[0] = fact[0] = 1; i < maxn; i++) {
		fact[i] = 1LL * i * fact[i - 1] % P;
		inv[i] = qp(i, P - 2);
		finv[i] = 1LL * inv[i] * finv[i - 1] % P;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &l[i], &r[i]);
		cnt[l[i]]++, cnt[r[i] + 1]--;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 1; i <= n; i++) {
		cnt[i] += cnt[i - 1];
		for (int j = 0; j <= m + m; j++) {
			s[i][j] = (s[i - 1][j] + binom(cnt[i] - j, i - j)) % P;
		}
	}
	for (int i = 0; i < 1 << m; i++) {
		unordered_set<int> S;
		int l = 1, r = n;
		for (int j = 0; j < m; j++) if (i >> j & 1) {
			l = max({l, ::l[a[j]], ::l[b[j]]});
			r = min({r, ::r[a[j]], ::r[b[j]]});
			S.insert(a[j]), S.insert(b[j]);
		}
		if (l <= r) ans = (ans + 1LL * (__builtin_popcount(i) & 1 ? P - 1 : 1) * (s[r][S.size()] - s[l - 1][S.size()] + P)) % P;
	}
	printf("%d\n", ans);
	return 0;
}