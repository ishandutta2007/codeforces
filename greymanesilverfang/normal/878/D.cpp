// Problem: Given k creatures, i-th one has stats a_i1, a_i2, ..., a_in.
// 3 types of queries: Create a new creature from the x-th one and the y-th one, stats are maximize
//                     ___________________________________________________________________ minimize
//                     Ask y-th stat of creature x

// Summarize solution:
// 

#include <bitset>
#include <cstdio>
using namespace std;
const int N = 111111, K = 13;
bitset<4096> f[N];
int a[N][K], id[N][K], mk[N][K];

void getmask(int* x, int* y, int* z, int k) {
	for (int i = 1, c = 1; c = i <= k; y[c] = i++)
		for (int j = 1; j <= k; ++j)
			c += x[i] > x[j] || x[i] == x[j] && i > j;
	for (int i = 1; i <= k; ++i)
		z[i] = z[i - 1] ^ 1 << y[i] - 1;
}

int main() {
	int n, k, q; scanf("%d%d%d", &n, &k, &q);
	for (int j = 1; j <= k; ++j)
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; ++i)
		getmask(a[i], id[i], mk[i], k);
	for (int i = 1; i <= k; ++i)
		for (int j = 1; j < 1 << k; ++j)
			f[i][j] = j >> i - 1 & 1;
	int cnt = k;
	for (int i = 1; i <= q; ++i) {
		int t, x, y; scanf("%d%d%d", &t, &x, &y);
		switch (t) {
			case 1: f[++cnt] = f[x] & f[y]; break;
			case 2: f[++cnt] = f[x] | f[y]; break;
			default: {
				int i; for (i = 1; !f[x][mk[y][i]]; ++i);
				printf("%d\n", a[y][id[y][i]]); break;
			}
		}
	}
}