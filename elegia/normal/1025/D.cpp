#include <cstdio>
#include <cstring>

using namespace std;

const int N = 710;

int n, cnt;

int a[N];
bool f[N][N], g[N][N], pre[N][N];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		f[i][i - 1] = g[i + 1][i] = true;
	for (int i = 0; i <= n; ++i)
		for (int j = i + 1; j <= n + 1; ++j)
			pre[i][j] = gcd(a[i], a[j]) != 1;
	for (int l = 1; l <= n; ++l) {
		for (int i = 1; i + l - 1 <= n; ++i) {
			int j = i + l - 1;
			for (int k = i; k <= j; ++k) {
				if (pre[k][j + 1])
					f[i][j] |= f[i][k - 1] && g[k + 1][j];
				if (pre[i - 1][k])
					g[i][j] |= f[i][k - 1] && g[k + 1][j];
			}
		}
	}
	puts(g[1][n] ? "Yes" : "No");
	return 0;
}