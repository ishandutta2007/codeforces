#include<stdio.h>
long long int n, m;
int main() {
	scanf("%lld%lld", &n, &m);
	long long int ans = 1;
	long long int p = 1;
	for (int i = 0; i < n; i++) {
		int ca = (m*i) % n;
		int cb = (m*(i+1)) % n;
		if (i >= 2 && i < n - 1) {
			if ((ca > 0 && ca < m) != (cb > 0 && cb < m))p++;
		}
		ans += p;
		printf("%lld ", ans);
	}
	return 0;
}