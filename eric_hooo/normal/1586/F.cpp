#include <bits/stdc++.h>
using namespace std;

int maxj = 0;
int k;
int a[1010][1010];

void Solve(int l, int r, int cur) {
	if (l >= r) return ;
	maxj = max(maxj, cur);
	int n = r - l + 1;
	int l1 = n / k, c1 = k - n % k, l2 = l1 + 1, c2 = k - c1;
	int now = l;
	while (c1--) {
		Solve(now, now + l1 - 1, cur + 1);
		for (int i = l; i < now; i++) {
			for (int j = now; j < now + l1; j++) {
				a[i][j] = cur;
			}
		}
		now += l1;
	}
	while (c2--) {
		Solve(now, now + l2 - 1, cur + 1);
		for (int i = l; i < now; i++) {
			for (int j = now; j < now + l2; j++) {
				a[i][j] = cur;
			}
		}
		now += l2;
	}
}

int main() {
	int n; scanf("%d%d", &n, &k);
	Solve(1, n, 1);
	printf("%d\n", maxj);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");
	return 0;
}