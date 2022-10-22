#include <bits/stdc++.h>
#define A(i) ((i) == 0 ? -1 : max(0ll, a[(i)] + tag[(i) / B]))
using namespace std;

const int B = 316;

long long a[100410], tag[400];
int f[100410], cnt[400];

void reBuild(int x, int val) {
	if (cnt[x] + val > B) return ;
	cnt[x] += val;
	for (int i = x * B; i < x * B + B; i++) {
		f[i] = A(i) < x * B ? i : f[A(i)];
	}
}

int Query(int x, int y) {
	while (f[x] != f[y]) {
		if (A(f[x]) < A(f[y])) swap(x, y);
		x = A(f[x]);
	}
	while (x != y) {
		if (x < y) swap(x, y);
		x = A(x);
	}
	return x;
}

int main() {
	a[0] = -1;
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++) {
		scanf("%I64d", &a[i]), a[i]--;
	}
	for (int i = 0; i < n; i += B) {
		reBuild(i / B, 0);
	}
	while (q--) {
		int op; scanf("%d", &op);
		if (op == 2) {
			int x, y; scanf("%d%d", &x, &y);
			printf("%d\n", Query(x - 1, y - 1) + 1);
		} else if (op == 1) {
			int l, r, x; scanf("%d%d%d", &l, &r, &x), l--, r--;
			for (int i = l / B * B; i < l; i++) a[i] += x;
			for (int i = r + 1; i < r / B * B + B; i++) a[i] += x;
			for (int i = l / B; i <= r / B; i++) {
				tag[i] -= x;
				reBuild(i, i != l / B && i != r / B);
			}
		}
	}
	return 0;
}