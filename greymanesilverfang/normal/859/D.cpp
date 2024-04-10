#include <cstdio>
#include <algorithm>
using namespace std;
double f[64][64], p[7][64], q[7][64], Q[7][64];
inline void maxi(double& a, double b) { if (a < b) a = b; }
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < 1<<n; ++i)
		for (int j = 0; j < 1<<n; ++j) {
			int x; scanf("%d", &x);
			f[i][j] = (double) x / 100;
		}
	fill(p[0], p[0] + 64, 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 1<<n; ++j) {
			for (int k = 0; k < 1<<i; ++k)
				p[i+1][j] += p[i][(j>>i^1)<<i^k] * f[j][(j>>i^1)<<i^k];
			p[i+1][j] *= p[i][j];
			q[i+1][j] = q[i][j] + Q[i][j>>i^1] + p[i+1][j] * (1<<i);
		}
		for (int j = 0; j < 1<<n; ++j)
			maxi(Q[i+1][j>>i+1], q[i+1][j]);
	}
	printf("%.12f", Q[n][0]);
}