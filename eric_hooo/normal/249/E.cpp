#include <bits/stdc++.h>
using namespace std;

const long long mod = 100000000000000000;

long long ADD(long long a, long long b) {return (a + b) % mod;}

long long MUL(long long a, long long b) {
	return a >= mod ? MUL(a % mod, b) : b < 0 ? mod - MUL(a, -b) : b ? ADD(MUL(a, b >> 5) << 5, (b & 31) * a) : 0;
}

long long SUB(long long a, long long b) {return (a - b + mod) % mod;}

long long Calc1(long long n) {
	if (n <= 0) return 0;
	long long m = n + 1;
	if (n & 1) m >>= 1;
	else n >>= 1;
	return MUL(n, m);
}

long long Calc1(long long l, long long r) {
	return SUB(Calc1(r), Calc1(l - 1));
}

long long Calc2(long long n) {
	if (n <= 0) return 0;
	long long a = n, b = n + 1, c = 2 * n + 1;
	if (a % 2 == 0) a /= 2;
	else if (b % 2 == 0) b /= 2;
	else c /= 2;
	if (a % 3 == 0) a /= 3;
	else if (b % 3 == 0) b /= 3;
	else c /= 3;
	return MUL(a, MUL(b, c));
}

long long Calc0(long long n) {
	if (n < 0) return 0;
	return (n + 1) % mod;
}

long long GetSum(long long n, long long m) {
	if (n == 0 || m == 0) return 0;
	long long ans = Calc1(min(n, m) * min(n, m));
	if (n == m) return ans;
	long long a, d, dd, l;
	if (n < m) {
		// [n * n + 1, n * n + n]
		a = Calc1(n * n + 1, n * n + n), d = (2 * n + 1) * n, dd = 2 * n, l = m - n;
	} else {
		// [(m + 1) * (m + 1) - m + 1, (m + 1) * (m + 1)]
		a = Calc1((m + 1) * (m + 1) - m + 1, (m + 1) * (m + 1)), d = (2 * m + 3) * m, dd = 2 * m, l = n - m;
	}
	ans = ADD(ans, MUL(a, l));
	ans = SUB(ans, MUL(Calc2(l - 2), dd));
	ans = ADD(ans, MUL(Calc1(l - 2), dd * l - dd - d));
	ans = ADD(ans, MUL(Calc0(l - 2), MUL(d, l) - d));
	return ans;
}

char buf[100];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		long long ans = GetSum(c, d) - GetSum(c, b - 1) - GetSum(a - 1, d) + GetSum(a - 1, b - 1);
		ans = (ans % mod + mod) % mod;
		if (ans > 9999999999 || 1ll * (c - a + 1) * (d - b + 1) >= 141421) {
			printf("..."), ans %= 10000000000;
			for (int i = 0; i < 10; i++) {
				buf[i] = '0' + ans % 10, ans /= 10;
			}
			buf[10] = '\0';
			reverse(buf, buf + 10);
			printf("%s\n", buf);
		} else printf("%lld\n", ans);
	}
	return 0;
}