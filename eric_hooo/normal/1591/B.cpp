#include <bits/stdc++.h>
using namespace std;

int a[200010];
int st[200010], tp;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		tp = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			int x = a[i];
			while (tp && st[tp - 1] <= x) tp--;
			st[tp++] = x;
		}
		printf("%d\n", tp - 1);
	}
	return 0;
}