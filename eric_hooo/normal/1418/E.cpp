#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mod = 998244353;

struct pii {
	int fi, se, id;
	bool operator < (const pii &A) const {
		return fi < A.fi || fi == A.fi && se < A.se;
	}
};

int d[200010];
long long sum[200010];
pii a[200010];
long long ans[200010];

long long power(long long a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

int main () {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]);
	}
	sort(d, d + n);
	for (int i = 0; i < n; i++) {
		sum[i + 1] = sum[i] + d[i];
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a[i].se, &a[i].fi);
		a[i].id = i;
	}
	sort(a, a + m);
	int pos = 0;
	for (int i = 0; i < m; i++) {
		while (pos < n && d[pos] < a[i].fi) pos++;
		long long s0 = sum[pos], s1 = sum[n] - sum[pos];
		s0 = s0 % mod * power(pos, mod - 2) % mod, s1 = s1 % mod * power(n - pos, mod - 2) % mod;
		if (n - pos < a[i].se) {
			ans[a[i].id] = 0;
			continue;
		}
		ans[a[i].id] = (n - pos - a[i].se) * s1 % mod;
		ans[a[i].id] = (ans[a[i].id] + (n - pos - a[i].se + 1) * power(n - pos + 1, mod - 2) % mod * pos % mod * s0) % mod;
	}
	for (int i = 0; i < m; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}