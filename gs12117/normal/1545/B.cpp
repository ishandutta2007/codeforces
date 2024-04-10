#include<cstdio>
#include<algorithm>
int n;
char s[100100];
const int mod = 998244353;
long long int fct[100100];
long long int mpow(int x, int y) {
	if (y == 0)return 1;
	long long int r = mpow(x, y / 2);
	r *= r;
	r %= mod;
	if (y % 2 == 1) {
		r *= x;
		r %= mod;
	}
	return r;
}
long long int minv(int x) {
	return mpow(x, mod - 2);
}
long long int comb(int x, int y) {
	return fct[x] * minv(fct[y]) % mod*minv(fct[x - y]) % mod;
}
int main() {
	fct[0] = 1;
	for (int i = 0; i < 100010; i++) {
		fct[i + 1] = (fct[i] * (i + 1)) % mod;
	}
	int tcn;
	scanf("%d", &tcn);
	while (tcn--) {
		scanf("%d", &n);
		scanf("%s", s);
		int zcnt, ocnt;
		zcnt = 0;
		ocnt = 0;
		int mo = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				zcnt++;
				ocnt = 0;
			}
			else {
				ocnt++;
				if (ocnt % 2 == 0) {
					mo++;
				}
			}
		}
		long long int ans = comb(zcnt + mo, mo);
		printf("%lld\n", ans);
	}
	return 0;
}