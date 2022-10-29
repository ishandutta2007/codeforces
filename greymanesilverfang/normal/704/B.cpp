// Problem: There are n chairs in a row, i-th chair is x_i metres from the origin.
// Calculate the least amount of time to visit every chair, starting at chair s and ending at chair e, given that:
// Arriving at i-th chair from one on the left takes a_i seconds,
// _____________________________________ right takes b_i seconds,
// Leaving from __________ to ___________ left takes c_i seconds,
// _____________________________________ right takes d_i seconds,
// and walking one metre takes one second.

#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 5005;
const ll INF = 1e14;
int n, S, E;
ll x[N], a[N], b[N], c[N], d[N], res[N][N / 2];
inline void Min(ll &a, ll b) { if (a > b) a = b;}

ll solve() {
	for (int i = 1; i <= n; ++i) {
		a[i] += x[i]; b[i] -= x[i];
		c[i] += x[i]; d[i] -= x[i];
	}
	a[S] = b[S] = c[E] = d[E] = 0;
	if (S > E) swap(S, E), swap(a, c), swap(b, d);
	fill(res[0], res[N], INF);
	res[0][0] = 0;
	for (int i = 1; i < n; ++i) {
		if (i != S && i != E)
			for (int j = 1; j <= n / 2; ++j) {
				Min(res[i][j], res[i-1][j+1] + a[i] + c[i]);
				// printf("%d %d %lld\n", i, j, res[i][j]);
				Min(res[i][j], res[i-1][ j ] + a[i] + d[i]);
				// printf("%d %d %lld\n", i, j, res[i][j]);
				if (j > 1 || i < S || i > E) Min(res[i][j], res[i-1][ j ] + b[i] + c[i]);
				// printf("%d %d %lld\n", i, j, res[i][j]);
				Min(res[i][j], res[i-1][j-1] + b[i] + d[i]);
				// printf("%d %d %lld\n", i, j, res[i][j]);
			}
		else if (i == S)
			for (int j = 1; j <= n / 2; ++j) {
				Min(res[i][j], res[i-1][ j ] + c[i]);
				// printf("%d %d %lld\n", i, j, res[i][j]);
				Min(res[i][j], res[i-1][j-1] + d[i]);
				// printf("%d %d %lld\n", i, j, res[i][j]);
			}
		else if (i == E)
			for (int j = 1; j <= n / 2; ++j) {
				Min(res[i][j], res[i-1][j+1] + a[i]);
				// printf("%d %d %lld\n", i, j, res[i][j]);
				Min(res[i][j], res[i-1][ j ] + b[i]);
				// printf("%d %d %lld\n", i, j, res[i][j]);
			}
	}
	return (res[n-1][1] + a[n] + c[n]);
}

int main() {
	scanf("%d%d%d", &n, &S, &E);
	for (int i = 1; i <= n; ++i) scanf("%lld", &x[i]);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; ++i) scanf("%lld", &b[i]);
	for (int i = 1; i <= n; ++i) scanf("%lld", &c[i]);
	for (int i = 1; i <= n; ++i) scanf("%lld", &d[i]);
	printf("%lld", solve());
}