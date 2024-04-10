#include<stdio.h>
const int mod = 1000000007;
int n;
char a[5010];
int lsc[5010];
int loccur[50];
int dpa[5010];
int sdpa[5010];
int dpb[5010];
int main() {
	scanf("%d", &n);
	scanf("%s", a);
	for (int i = 0; i < 30; i++) {
		loccur[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		lsc[i] = loccur[a[i] - 'a'];
		loccur[a[i] - 'a'] = i;
	}
	for (int i = 0; i < n; i++) {
		if (lsc[i] == -1)dpa[i] = 1;
		else dpa[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		sdpa[0] = 0;
		for (int j = 0; j < n; j++) {
			sdpa[j + 1] = (sdpa[j] + dpa[j]) % mod;
		}
		for (int j = 0; j < n; j++) {
			dpb[j] = (sdpa[j + 1] + mod - sdpa[lsc[j] + 1]) % mod;
		}
		for (int j = 0; j < n; j++) {
			dpa[j] = dpb[j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += dpa[i];
		ans %= mod;
	}
	printf("%d", ans);
	return 0;
}