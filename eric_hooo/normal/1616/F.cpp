#include <bits/stdc++.h>
using namespace std;

int G[70][70];
int A[5000][300];
int X[300];
int N, M;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		memset(G, -1, sizeof(G)), memset(A, 0, sizeof(A));
		int n, m; scanf("%d%d", &n, &m), N = m, M = 0;
		for (int i = 0; i < m; i++) {
			int x, y, w; scanf("%d%d%d", &x, &y, &w), x--, y--;
			G[x][y] = G[y][x] = i;
			if (w != -1) A[M][i] = 1, A[M][N] = w - 1, M++;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					if (G[i][j] != -1 && G[j][k] != -1 && G[k][i] != -1) {
						int x = G[i][j], y = G[j][k], z = G[k][i];
						A[M][x] = A[M][y] = A[M][z] = 1, M++;
					}
				}
			}
		}
		int C = 0;
		for (int i = 0; i < N; i++) {
			int p = -1;
			for (int j = C; j < M; j++) {
				if (A[j][i]) {
					p = j;
					break;
				}
			}
			if (p == -1) continue;
			for (int j = 0; j <= N; j++) {
				swap(A[C][j], A[p][j]);
			}
			if (A[C][i] == 2) {
				for (int j = 0; j <= N; j++) {
					A[C][j] = A[C][j] * 2 % 3;
				}
			}
			for (int j = C + 1; j < M; j++) {
				int mul = (3 - A[j][i]) % 3;
				if (mul == 0) continue;
				for (int k = 0; k <= N; k++) {
					A[j][k] = (A[j][k] + mul * A[C][k]) % 3;
				}
			}
			C++;
		}
		for (int i = C - 1; i >= 0; i--) {
			int p = 0; while (!A[i][p]) p++;
			X[p] = A[i][N];
			for (int j = p + 1; j < N; j++) {
				X[p] = (X[p] - A[i][j] * X[j] + 3333) % 3;
			}
		}
		for (int i = C; i < M; i++) {
			int val = 0;
			for (int j = 0; j < N; j++) {
				val = (val + A[i][j] * X[j]) % 3;
			}
			if (val != A[i][N]) {
				printf("-1\n");
				goto END;
			}
		}
		for (int i = 0; i < N; i++) {
			printf("%d ", X[i] + 1);
		}
		printf("\n");
		END:;
	}
	return 0;
}