#include <bits/stdc++.h>

using namespace std;

int n, q, t, l, r, x, f[200001], lst[200001];

int gf(int x) { return f[x] == x ? x : f[x] = gf(f[x]); }

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		f[i] = i;
		lst[i] = -1;
	}
	while (q--) {
		scanf("%d", &t);
		if (t == 0) {
			scanf("%d%d%d", &l, &r, &x);
			if (x == 0) {
				l = gf(l - 1);
				while ((r = gf(r)) > l) {
					lst[l] = max(lst[l], lst[r]);
					f[r--] = l;
				}
			} else {
				r = gf(r);
				lst[r] = max(lst[r], l - 1);
			}
		} else {
			scanf("%d", &x);
			puts(f[x] == x ? lst[x] != -1 && gf(lst[x]) == gf(x - 1) ? "YES" : "N/A" : "NO");
		}
	}
	return 0;
}