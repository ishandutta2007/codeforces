#include <bits/stdc++.h>

using namespace std;
#define NO { puts("-1"); continue; }

int t, n, a[200001], cn, cp, k;
bool ans[200001];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		cn = cp = k = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			ans[i] = 0;
			if (a[i] == -1) ++cn;
			if (a[i] == +1) ++cp;
		}
		if (cn + cp & 1) NO
		k = n;
		if (cn > cp) {
			for (int i = 2; i <= n && cn > cp; ++i)
				if (a[i] == -1 && !ans[i - 1]) {
					ans[i] = 1;
					--k;
					++cp;
					--cn;
				}
			if (cn > cp) NO
		} else {
			for (int i = 2; i <= n && cp > cn; ++i)
				if (a[i] == +1 && !ans[i - 1]) {
					ans[i] = 1;
					--k;
					++cn;
					--cp;
				}
			if (cp > cn) NO
		}
		printf("%d\n", k);
		for (int i = 1; i <= n; ++i)
			if (!ans[i])
				if (i < n && ans[i + 1])
					printf("%d %d\n", i, i + 1); else
					printf("%d %d\n", i, i);
	}
	return 0;
}