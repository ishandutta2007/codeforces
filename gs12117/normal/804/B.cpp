#include<cstdio>
#include<cstring>
char s[1001000];
const int mod = 1000000007;
int n;
int main() {
	scanf("%s", s);
	n = strlen(s);
	int ans = 0;
	int bv = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') {
			bv = bv * 2 + 1;
			bv %= mod;
		}
		else {
			ans += bv;
			ans %= mod;
		}
	}
	printf("%d", ans);
	return 0;
}