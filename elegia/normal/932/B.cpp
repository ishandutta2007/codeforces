#include <cstdio>
#include <cstring>

#include <algorithm>
#include <numeric>

const int N = 1000010;

int g[N];
int cnt[10][N];

int main() {
	for (int i = 1; i < 10; ++i)
		g[i] = i;
	for (int i = 10; i <= 1000000; ++i) {
		int prod = 1;
		int x = i;
		while (x) {
			if (x % 10 != 0)
				prod *= x % 10;
			x /= 10;
		}
		g[i] = g[prod];
	}
	for (int i = 1; i <= 1000000; ++i)
		++cnt[g[i]][i];
	for (int i = 1; i < 10; ++i)
		for (int j = 1; j <= 1000000; ++j)
			cnt[i][j] += cnt[i][j - 1];
	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", cnt[k][r] - cnt[k][l - 1]);
	}
	return 0;
}