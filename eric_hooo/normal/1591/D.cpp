#include <bits/stdc++.h>
using namespace std;

int a[500010];
int T[500010];
int n;

void modify(int x, int v) {
	while (x <= n) T[x] += v, x += x & -x;
}

int query(int x) {
	int res = 0;
	while (x) res += T[x], x -= x & -x;
	return res;
}

int main() {
	int Case; scanf("%d", &Case);
	while (Case--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			T[i] = 0;
		}
		long long sum = 0; int bad = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum += i - 1 - query(a[i]);
			if (query(a[i] - 1) + 1 == query(a[i])) {
				bad = 1;
			}
			modify(a[i], 1);
		}
		if (bad == 1) printf("YES\n");
		else if (sum & 1) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}