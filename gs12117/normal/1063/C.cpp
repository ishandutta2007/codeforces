#include<cstdio>
const long long int div = 200000000;
const long long int xf = 400000000;
const long long int yf = 400000000;
int n;
char s[110];
int main() {
	scanf("%d", &n);
	long long int vl = 1e12;
	for (int i = 0; i < n; i++) {
		long long int vp = vl + (1LL << (n + 3 - i));
		long long int x = vp / div + xf;
		long long int y = vp % div + yf;
		printf("%lld %lld\n", x, y);
		fflush(stdout);
		scanf("%s", s);
		if (s[0] == 'b')vl = vp;
	}
	long long int vres = vl + 3;
	long long int xres = vres / div + xf;
	long long int yres = vres % div + yf;
	printf("%lld %lld %lld %lld\n", xres, yres, xres - 1, yres + 300000000);
	return 0;
}