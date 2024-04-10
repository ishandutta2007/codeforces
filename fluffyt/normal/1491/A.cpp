#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int a[MAXN], n, Q;

int main() {
	scanf("%d%d", &n, &Q);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	int c0 = 0;
	for (int i = 1; i <= n; i++) c0 += !a[i];
	while (Q--) {
		int t, x; scanf("%d%d", &t, &x);
		if (t == 1) {
			a[x] = 1 - a[x];
			if (a[x]) --c0;
			else ++c0;
		} else {
			if ((n - c0) < x) puts("0");
			else puts("1");
		}
	}
	return 0;
}