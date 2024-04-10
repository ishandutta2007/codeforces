#include<stdio.h>
int f, w, h;
const int mod = 1000000007;
long long int fct[201000];
long long int ifct[201000];
long long int comb(int x, int y) {
	if (x < 0 || y<0 || y>x)return 0;
	return fct[x] * ifct[x - y] % mod*ifct[y] % mod;
}
int mpow(int x, int y) {
	if (y == 0)return 1;
	long long int res = mpow(x, y / 2);
	res *= res;
	res %= mod;
	if (y % 2 == 1) {
		res *= x;
		res %= mod;
	}
	return res;
}
int inv(int x) {
	return mpow(x, mod - 2);
}
int main() {
	fct[0] = 1;
	for (int i = 0; i < 200100; i++) {
		fct[i + 1] = fct[i] * (i + 1) % mod;
	}
	ifct[200100] = inv(fct[200100]);
	for (int i = 200100; i > 0; i--) {
		ifct[i - 1] = ifct[i] * i % mod;
	}
	scanf("%d%d%d", &f, &w, &h);
	if (w == 0) {
		printf("1");
		return 0;
	}
	if (f == 0) {
		if (w > h) {
			printf("1");
		}
		else {
			printf("0");
		}
		return 0;
	}
	long long int ans = 0;
	for (int i = 0; i*(h + 1) <= w; i++) {
		ans += comb(f + 1, i)*comb(w - i*h - 1, i - 1) % mod;
		ans %= mod;
	}
	ans *= inv(comb(f + w, w));
	ans %= mod;
	printf("%I64d", ans);
	return 0;
}