#include<cstdio>
int mod = 998244353;
long long int cres[2010][4010];
long long int tmp[4010];
long long int fct[4010];
int n, m, p;
void lpow(int x) {
	for (int i = 0; i <= 2 * n; i++) {
		tmp[i] = 0;
	}
	for (int i = 0; i <= 2 * n; i++) {
		tmp[i] += cres[x][i];
		tmp[i + 1] += 2 * (mod - cres[x][i]);
		tmp[i + 2] += 2 * cres[x][i];
	}
	for (int i = 0; i <= 2 * n; i++) {
		cres[x][i] = tmp[i] % mod;
	}
}
void rpow(int x) {
	for (int i = 0; i <= 2 * n; i++) {
		tmp[i] = 0;
	}
	for (int i = 0; i <= 2 * n; i++) {
		tmp[i + 1] += 2 * cres[x][i];
		tmp[i + 2] += 2 * (mod - cres[x][i]);
	}
	for (int i = 0; i <= 2 * n; i++) {
		cres[x][i] = tmp[i] % mod;
	}
}
void pcopy(int x, int y) {
	for (int i = 0; i <= 2 * n; i++) {
		cres[y][i] = cres[x][i];
	}
}
void divconq(int l, int r) {
	if (l == r)return;
	int lmid = (l + r) / 2;
	int rmid = lmid + 1;
	pcopy(l, rmid);
	for (int i = 0; i < (r - lmid); i++) {
		lpow(l);
	}
	for (int i = 0; i < (rmid - l); i++) {
		rpow(rmid);
	}
	divconq(l, lmid);
	divconq(rmid, r);
}
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
	scanf("%d%d%d", &n, &m, &p);
	cres[0][0] = 1;
	divconq(0, n);
	long long int ans = 0;
	fct[0] = 1;
	for (int i = 0; i <= 2 * n; i++) {
		tmp[i] = minv(i + 1);
		fct[i + 1] = (fct[i] * (i + 1)) % mod;
	}
	for (int i = m; i <= n; i++) {
		long long int tans = 0;
		for (int j = 0; j <= 2 * n; j++) {
			tans += tmp[j] * cres[i][j];
			tans %= mod;
		}
		tans *= comb(n, i);
		tans %= mod;
		ans += tans;
		ans %= mod;
	}
	ans *= p;
	ans %= mod;
	printf("%lld", ans);
	return 0;
}