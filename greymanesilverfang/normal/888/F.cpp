// Problem: Given a planar graph with n vertices on a circle.
// How many ways are there to add edges to build an MST?

#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 500;
long long a[N][N], f[N][N], g[N][N], res = 0, mod = 1e9 + 7;

int main() {
	fill(f[0], f[1], 1);
	fill(g[0], g[1], 1);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%lld", &a[i][j]);
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			if (a[j][(j + i) % n])
				for (int k = 1; k <= i; ++k)
					(g[i][j] += f[k - 1][j] * f[i - k][(j + k) % n]) %= mod;
		for (int j = 0; j < n; ++j)
			for (int k = 1; k <= i; ++k)
				(f[i][j] += g[k][j] * f[i - k][(j + k) % n]) %= mod;
	}
	for (int i = 2; i <= n; ++i)
		(res += g[i - 1][0] * f[n - i][i - 1]) %= mod;
	printf("%lld", res);
}