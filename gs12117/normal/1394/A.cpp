#include<cstdio>
#include<algorithm>
#include<functional>
int n, d, m;
int a[100100];
int b[100100];
int bsz;
long long int bsum[100100];
int c[100100];
int csz;
long long int csum[100100];
int main() {
	scanf("%d%d%d", &n, &d, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > m) {
			c[csz] = -a[i];
			csz++;
		}
		else {
			b[bsz] = -a[i];
			bsz++;
		}
	}
	std::sort(b, b + bsz);
	std::sort(c, c + csz);
	for (int i = 0; i < n + 3; i++) {
		bsum[i + 1] = bsum[i] + b[i];
		csum[i + 1] = csum[i] + c[i];
	}
	long long int ans = -bsum[n];
	for (int i = 1;; i++) {
		int bloc = n - 1 - (i - 1)*(d + 1);
		if (bloc < 0)break;
		long long int tans = -bsum[bloc] - csum[i];
		if (ans < tans)ans = tans;
	}
	printf("%lld\n", ans);
	return 0;
}