#include <bits/stdc++.h>
using namespace std;

int n;
int a[1510][1510];
int pos[2300000];
int row[1510], col[1510];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			pos[a[i][j]] = i * n + j;
		}
	}
	long long ans = 0;
	for (int it = 1; it <= n * n; it++) {
		int x = pos[it] / n, y = pos[it] % n;
		ans += row[x] * (n - col[y] - 1);
		ans += (n - row[x] - 1) * col[y];
		row[x]++, col[y]++;
	}
	ans /= 2;
	printf("%lld\n", ans);
	return 0;
}