#include <bits/stdc++.h>

using namespace std;
#define NO { puts("-1"); continue; }

int n, x, ai, cnt[500001];

int main() {
	scanf("%d%d", &n, &x);
	while (n--) {
		scanf("%d", &ai);
		while (ai < x && ++cnt[ai] == ai + 1)
			cnt[ai++] = 0;
	}
	for (int i = 1; i < x; ++i)
		if (cnt[i]) {
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}