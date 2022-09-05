#include <bits/stdc++.h>

using namespace std;

int main() {
	static int n, m, a[110], b[110], c[110];
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", b + i);
	}
	for (int l = 1; l <= n; ++l) {
		memset(c, 0, sizeof c);
		for (int r = l; r <= n; ++r) {
			++c[a[r]];
			bool ok = 1;
			for (int i = 1; i <= m; ++i) {
				if(b[i] != c[i]) {
					ok = 0;
					break;
				}
			}
			if(ok) {
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}