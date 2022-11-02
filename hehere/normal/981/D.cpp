#include <cstdio>
#include <cstring>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
typedef long long LL;
const int maxN = 50 + 5;
int n, k;
LL a[maxN], s[maxN];
char f[maxN][maxN];
LL ans = 0;

int main() {
	
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	s[0] = 0;
	for(int i = 1; i <= n; ++i) s[i] = s[i-1] + a[i];
	if(k == 1) {
		printf("%lld\n", s[n]); return 0;
	}
	
	for(LL t = (1LL << 58LL); t; t >>= 1LL) {
		ans |= t;
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; ++i) f[i][1] = ((s[i] & ans) == ans);
		for(int i = 2; i <= n; ++i) {
			for(int j = 2; j <= i; ++j) {
				for(int p = j - 1; p < i; ++p) {
					f[i][j] |= (f[p][j-1] && (((s[i] - s[p]) & ans) == ans));
				}
			}
		}
		if(!f[n][k]) ans ^= t;
	}
	printf("%lld\n", ans);
	return 0;
}