#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

int n, m, k;
int G[110][110], A[210][210], T[210][210];
int F1[110][110], F2[110][110];
int deg[110];

void matrixmul(int f[210][210], int g[210][210], int h[210][210]) {
	static int tmp[210][210];
	for (int i = 0; i < 200; i++) for (int j = 0; j < 200; j++) {
		tmp[i][j] = 0;
		for (int k = 0; k < 200; k++) {
			ADD(tmp[i][j], 1ll * f[i][k] * g[k][j] % mod);
		}
	}
	for (int i = 0; i < 200; i++) for (int j = 0; j < 200; j++) {
		h[i][j] = tmp[i][j];
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	if (k == 1) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y), x--, y--;
		G[x][y] = 1, G[y][x] = 1, deg[x]++, deg[y]++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = G[i][j], A[i][n + j] = i == j;
			A[n + i][j] = i == j ? mod - deg[i] + 1 : 0;
			T[i][j] = i == j, T[n + i][n + j] = i == j;
		}
	}
	k -= 2;
	for (int it = 0; it < 14; it++) {
		if (k >> it & 1) matrixmul(T, A, T);
		matrixmul(A, A, A);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			F1[i][j] = G[i][j];
			for (int k = 0; k < n; k++) {
				ADD(F2[i][j], G[i][k] * G[k][j]);
			}
			SUB(F2[i][j], i == j ? deg[i] : 0);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + n; j++) {
			ADD(ans, 1ll * (j < n ? F2[j][i] : F1[j - n][i]) * T[j][i] % mod);
		}
	}
	printf("%d\n", ans);
	return 0;
}