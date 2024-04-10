#include <cstdio>
int MOD = 1e9 + 7, p[1001], s[1001];
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
		s[i] = (MOD+s[i-1]*2%MOD-s[p[i]-1]+2)%MOD;
	}
	printf("%d", s[n]);
}