#include<cstdio>
int n;
long long int a[300100];
long long int b[300100];
int c[300100];
int main() {
	scanf("%d", &n);
	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &a[i], &b[i]);
		for (int j = 0; j < 62; j++) {
			if (b[i] & (1LL << j))c[i] = j;
		}
		sum += a[i];
	}
	if (sum < 0) {
		for (int i = 0; i < n; i++) {
			a[i] = -a[i];
		}
	}
	long long int s = 0;
	for (int i = 0; i < 62; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			if (c[j] == i) {
				long long int t = a[j];
				for (int k = 0; k < i; k++) {
					if (s&(1LL << k)) {
						if (b[j] & (1LL << k))t = -t;
					}
				}
				sum += t;
			}
		}
		if (sum > 0) {
			s ^= (1LL << i);
		}
	}
	printf("%lld", s);
	return 0;
}