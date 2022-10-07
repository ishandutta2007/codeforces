#include<cstdio>
#include<algorithm>
long long int t;
int n;
int a[200100];
long long int b[200100];
long long int cyc;
struct astro {
	int mpc;
	long long int ftime;
	int idx;
	bool operator<(const astro&r)const {
		return mpc < r.mpc || (mpc == r.mpc&&ftime < r.ftime);
	}
};
astro d[200100];
long long int ans[200100];
long long int gcd(long long int x, long long int y) {
	if (x == 0)return y;
	return gcd(y%x, x);
}
std::pair<long long int, long long int> egcd(long long int x, long long int y) {
	if (x == 0)return{ 0,1 };
	auto s = egcd(y%x, x);
	return{ s.second - s.first*(y / x), s.first };
}
long long int modinv(long long int x, long long int y) {
	return (egcd(x, y).first + 10 * y) % y;
}
long long int modmult(long long int x, long long int y, long long int mod) {
	long long int res = 0;
	while (x > 0) {
		if (x % 2 == 1) {
			res += y;
			res %= mod;
		}
		x /= 2;
		y *= 2;
		y %= mod;
	}
	return res%mod;
}
long long int divmult(long long int x, long long int y, long long int mod) {
	long long int ansd = 0;
	long long int ansm = 0;
	long long int yd = y / mod;
	long long int ym = y % mod;
	while (x > 0) {
		if (x % 2 == 1) {
			ansd += yd;
			ansm += ym;
			ansd += ansm / mod;
			ansm %= mod;
		}
		x /= 2;
		yd *= 2;
		ym *= 2;
		yd += ym / mod;
		ym %= mod;
	}
	return ansd;
}
int main() {
	scanf("%I64d%d", &t, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i != 0)cyc += a[i];
		b[i] = cyc;
	}
	cyc += a[0];
	int pcyc = gcd(t, cyc);
	cyc /= pcyc;
	t /= pcyc;
	for (int i = 0; i < n; i++) {
		d[i].mpc = b[i] % pcyc;
		d[i].ftime = modmult((b[i] / pcyc), modinv(t, cyc), cyc);
		d[i].idx = i;
	}
	std::sort(d, d + n);
	for (int i = 0; i < n;) {
		int r = i;
		while (r < n&&d[i].mpc == d[r].mpc)r++;
		long long int s = t;
		for (int j = i + 1; j < r; j++) {
			long long int p = divmult(d[j].ftime, t, cyc) - divmult(d[j - 1].ftime, t, cyc);
			ans[d[j].idx] = p;
			s -= p;
		}
		ans[d[i].idx] = s;
		i = r;
	}
	for (int i = 0; i < n; i++) {
		printf("%I64d ", ans[i]);
	}
	return 0;
}