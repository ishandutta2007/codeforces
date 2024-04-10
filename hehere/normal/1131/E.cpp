#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxN = 100000 + 233;
const long long maxA = 1000000000 + 233;
int n;
long long a[26];

int main() {
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	for(int i = 0; i < n; ++ i) {
		static char s[maxN];
		scanf("%s", s);
		int m = strlen(s);
		for(int i = 0; i < m; ++ i) s[i] -= 'a';
		int pre = 0, post = 0;
		while(pre < m && s[pre] == s[0]) ++ pre;
		while(post < m && s[m - 1 - post] == s[m - 1]) ++ post;
		for(int c = 0; c < 26; ++ c) {
			if(pre == m) if(s[0] == c) a[c] = (a[c] + 1) * m + a[c]; else a[c] = std::min(a[c], 1LL);
			else if(a[c]) a[c] = 1 + (s[0] == c ? pre : 0) + (s[m - 1] == c ? post : 0);
			a[c] = std::min(a[c], maxA);
		}
		for(int i = 0; i < m; ++ i) {
			int j = i;
			for(; s[i] == s[j] && j < m; ++ j);
			a[(int)s[i]] = std::max(a[(int)s[i]], (long long)j - i);
			i = j - 1;
		}
		// for(int c = 0; c < 26; ++c) printf("%lld ", a[c]); printf("\n");
	}
	long long ans = 0;
	for(int c = 0; c < 26; ++ c) ans = std::max(ans, a[c]);
	printf("%d\n", (int)ans);
	return 0;
}