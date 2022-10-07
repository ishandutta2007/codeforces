#include<cstdio>
long long int mod = 100000000000000000;
long long int mmul(long long int x, long long int y) {
	x %= mod;
	y %= mod;
	long long int res = 0;
	while (y) {
		res += x*(y % 32);
		res %= mod;
		y /= 32;
		x *= 32;
		x %= mod;
	}
	return res;
}
long long int mpow(long long int x, long long int y) {
	if (y == 0)return 1;
	long long int r = mpow(x, y / 2);
	r = mmul(r, r);
	if (y % 2 == 1) {
		r = mmul(r, x);
	}
	return r;
}
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		long long int x;
		scanf("%lld", &x);
		x *= 1000000;
		x += 131072 - (x % 131072);
		if (x % 10 == 0)x += 131072;
		long long int res = 500;
		long long int powt = 10;
		long long int resacc = 1;
		for (int i = 0; i < 17; i++) {
			while (mpow(2, res) % powt != x%powt) {
				res += resacc;
			}
			if (i != 0)resacc *= 5;
			else resacc *= 4;
			powt *= 10;
		}
		printf("%lld\n", res);
	}
	return 0;
}