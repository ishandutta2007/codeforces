#include<stdio.h>
int n, m, x;
int a[100100];
int rn[1 << 10];
int nrn[1 << 10];
const int p = 1 << 10;
int main() {
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		rn[a[i]]++;
	}
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		int pn = 0;
		for (int j = 0; j < p; j++) {
			cnt += rn[j];
			int spn = cnt >> 1;
			nrn[j] += spn - pn;
			nrn[j^x] += rn[j] + pn - spn;
			pn = spn;
		}
		for (int j = 0; j < p; j++) {
			rn[j] = nrn[j];
			nrn[j] = 0;
		}
	}
	int mn, mx;
	mn = 100000000;
	mx = -1;
	for (int j = 0; j < p; j++) {
		if (rn[j] != 0) {
			if (mn > j)mn = j;
			if (mx < j)mx = j;
		}
	}
	printf("%d %d\n", mx, mn);
	return 0;
}