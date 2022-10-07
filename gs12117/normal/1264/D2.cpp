#include<cstdio>
const long long int mod = 998244353;
int n, m, p;
char s[1001000];
long long int fct[1001000];
long long int ifct[1001000];
long long int fd[1001000];
long long int sd[1001000];
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
long long int minv(long long int x) {
	return mpow(x, mod - 2);
}
long long int comb(int n, int r) {
	if (r<0 || r>n)return 0;
	return fct[n] * ifct[r] % mod*ifct[n - r] % mod;
}
int main() {
	scanf("%s", s);
	for (n = 0; s[n]; n++);
	for (int i = 0; i < n; i++) {
		if (s[i] == ')')p++;
		else if (s[i] == '?')m++;
	}
	fct[0] = 1;
	for (int i = 0; i < n; i++) {
		fct[i + 1] = (i + 1)*fct[i] % mod;
	}
	ifct[n] = minv(fct[n]);
	for (int i = n - 1; i >= 0; i--) {
		ifct[i] = (i + 1)*ifct[i + 1] % mod;
	}
	fd[n] = 0;
	sd[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		fd[i] = fd[i + 1] + comb(m, i + 1 - p);
		fd[i] %= mod;
		sd[i] = sd[i + 1] + comb(m - 1, i + 1 - p);
		sd[i] %= mod;
	}
	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')ans += fd[i];
		else if (s[i] == '?')ans += sd[i];
		ans %= mod;
	}
	printf("%lld", ans);
	return 0;
}