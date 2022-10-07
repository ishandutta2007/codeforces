#include<cstdio>
#include<algorithm>
int n, p;
int a[1001000];
const long long int mod = 1000000007;
const long long int diff_max = mod;
long long int modpow(long long int x, long long int y) {
	if (y == 0)return 1;
	long long int r = modpow(x, y / 2);
	r *= r;
	r %= mod;
	if (y % 2 == 1) {
		r *= x;
		r %= mod;
	}
	return r;
}
int main() {
	int tcn;
	scanf("%d", &tcn);
	while (tcn--) {
		scanf("%d%d", &n, &p);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		long long int ans;
		if (p == 1) {
			ans = n % 2;
		}
		else {
			std::sort(a, a + n);
			int base = a[n - 1];
			long long int mindiff = 0;
			ans = 0;
			for (int i = n - 1; i >= 0; i--) {
				while (base > a[i]) {
					base--;
					mindiff *= p;
					if (mindiff >= diff_max) {
						mindiff = diff_max;
					}
					if (mindiff == 0 || mindiff >= diff_max) {
						base = a[i];
						break;
					}
				}
				if (mindiff == 0) {
					mindiff++;
					ans += modpow(p, a[i]);
					ans %= mod;
				}
				else {
					mindiff--;
					ans += mod - modpow(p, a[i]);
					ans %= mod;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}