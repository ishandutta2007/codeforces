#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 200005;

int n, d[N], tot;

char s[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &n, s + 1); tot = 0;
		for (int i = 2; i <= n; i++) {
			if (s[i] == s[i - 1]) d[++tot] = i;
		}
		int i = 1, j = 1, ans = 0;
		while (i <= n) {
			while (j <= tot && d[j] < i) ++j;
			if (j > tot) {
				while (s[n] == s[n - 1]) --n;
				--n;
			} else ++j;
			ans++;
			while (i < n && s[i] == s[i + 1]) i++;
			++i;
		}
		printf("%d\n", ans);
	}	
	return 0;
}