#include<cstdio>
int n, m;
int a[510][510];
int b[510][510];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		int res = 0;
		for (int j = 0; j < m; j++) {
			res ^= a[i][j] ^ b[i][j];
		}
		if (res != 0) {
			printf("No");
			return 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int res = 0;
		for (int j = 0; j < n; j++) {
			res ^= a[j][i] ^ b[j][i];
		}
		if (res != 0) {
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}