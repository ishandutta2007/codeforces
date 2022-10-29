#include <cstdio>
const int N = 1e5;
int n, a[N], k;

void Solve(int L, int Min, int Len) {
	if (k > 1 && Len > 1) {
		k -= 2;
		Solve(L, Min + (Len + 1) / 2, Len / 2);
		Solve(L + Len / 2, Min, (Len + 1) / 2);
		return;
	}
	for (int i = 0; i < Len; ++i)
		a[L + i] = Min + i;
}

int main() {
	scanf("%d%d", &n, &k);
	if (k % 2 == 0 || k >= 2 * n) {
		printf("-1");
		return 0;
	}
	Solve(0, 1, n);
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
}