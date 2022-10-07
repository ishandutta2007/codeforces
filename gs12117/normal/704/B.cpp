#include<cstdio>
long long int dpa[10100];
long long int dpb[10100];
int x[5010];
int a[5010];
int b[5010];
int c[5010];
int d[5010];
int n, s, e;
int main() {
	scanf("%d%d%d", &n, &s, &e);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]);
	}
	for (int i = 0; i <= 2 * n; i++) {
		dpa[i] = 1e18;
	}
	int sig = 0;
	if (s == 1) {
		dpa[1] = d[0];
		sig++;
	}
	else if (e == 1) {
		dpa[1] = b[0];
		sig--;
	}
	else {
		dpa[2] = d[0] + b[0];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 2 * n; j++) {
			dpa[j] += ((long long int)x[i] - x[i - 1])*j;
		}
		for (int j = 0; j <= 2 * n; j++) {
			dpb[j] = 1e18;
		}
		if (s - 1 == i) {
			sig++;
		}
		else if (e - 1 == i) {
			sig--;
		}
		for (int j = 1; j < 2 * n; j++) {
			if (i == s - 1) {
				if (dpb[j - 1] > dpa[j] + c[i])dpb[j - 1] = dpa[j] + c[i];
				if (dpb[j + 1] > dpa[j] + d[i])dpb[j + 1] = dpa[j] + d[i];
			}
			else if (i == e - 1) {
				if (dpb[j - 1] > dpa[j] + a[i])dpb[j - 1] = dpa[j] + a[i];
				if (dpb[j + 1] > dpa[j] + b[i])dpb[j + 1] = dpa[j] + b[i];
			}
			else {
				if (j == 1) {
					if (sig == -1 && dpb[j] > dpa[j] + c[i] + b[i])dpb[j] = dpa[j] + c[i] + b[i];
					if (sig == 1 && dpb[j] > dpa[j] + d[i] + a[i])dpb[j] = dpa[j] + d[i] + a[i];
					if (dpb[j + 2] > dpa[j] + d[i] + b[i])dpb[j + 2] = dpa[j] + d[i] + b[i];
				}
				else {
					if (dpb[j - 2] > dpa[j] + c[i] + a[i])dpb[j - 2] = dpa[j] + c[i] + a[i];
					if (dpb[j] > dpa[j] + c[i] + b[i])dpb[j] = dpa[j] + c[i] + b[i];
					if (dpb[j] > dpa[j] + d[i] + a[i])dpb[j] = dpa[j] + d[i] + a[i];
					if (dpb[j + 2] > dpa[j] + d[i] + b[i])dpb[j + 2] = dpa[j] + d[i] + b[i];
				}
			}
		}
		for (int j = 0; j <= 2 * n; j++) {
			dpa[j] = dpb[j];
		}
	}
	printf("%lld", dpa[0]);
	return 0;
}