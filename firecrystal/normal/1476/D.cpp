// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 3e5 + 5;

int n, ans[N];

char s[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &n, s + 1);
		int s0 = 0, s1 = 0;
		for (int i = 0; i <= n; i++) ans[i] = 1;
		for (int i = 0; i < n; i++) {
			int c0 = 0, c1 = 0;
			if (s[i + 1] == 'L') c0++, c0 += s1;
			else c1++, c1 += s0;
			s0 = c0, s1 = c1;
			ans[i + 1] += s0;
		}
		s0 = 0, s1 = 0;
		for (int i = n; i; i--) {
			int c0 = 0, c1 = 0;
			if (s[i] == 'L') c0++, c0 += s1;
			else c1++, c1 += s0;
			s0 = c0, s1 = c1;
			ans[i - 1] += s1;
		}
		for (int i = 0; i <= n; i++) printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}