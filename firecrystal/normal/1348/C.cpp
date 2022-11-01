#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 100005;

int n, K, cnt[N];

char s[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%s", &n, &K, s + 1);		
		sort(s + 1, s + 1 + n);
		if (s[1] == s[K]) {
			if (K == n) {
				putchar(s[1]);
				puts("");
			} else if (s[K + 1] == s[n]) {
				putchar(s[1]);
				int len = n - (K + 1) + 1;
				int z = len % K ? len / K + 1 : len / K;
				while(z--) putchar(s[n]);
				puts("");
			} else {
				putchar(s[1]);
				for (int i = K + 1; i <= n; i++) putchar(s[i]);
				puts("");
			}
		} else {
			putchar(s[K]);
			puts("");
		}
	}
	return 0;
}