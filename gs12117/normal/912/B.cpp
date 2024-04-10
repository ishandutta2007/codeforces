#include<cstdio>
long long int n, m;
int main() {
	scanf("%lld%lld", &n, &m);
	long long int ans = 0;
	long long int sd = 0;
	while (sd < n) {
		sd = sd * 2 + 1;
	}
	if (m == 1)ans = n;
	else {
		ans = sd;
	}
	printf("%lld", ans);
	return 0;
}