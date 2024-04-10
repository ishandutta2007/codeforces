#include<cstdio>
int pl, pr;
int n, m;
int edge[100100][3];
void makeedge(int x, int y, int z) {
	edge[m][0] = x;
	edge[m][1] = y;
	edge[m][2] = z;
	m++;
}
int main() {
	scanf("%d%d", &pl, &pr);
	int d = pr - pl + 1;
	n = 2;
	while ((1 << (n - 2)) < d) {
		n++;
	}
	if ((1 << (n - 2)) == d) {
		for (int i = 2; i < n; i++) {
			for (int j = 1; j < i; j++) {
				makeedge(j, i, 1 << (i - 2));
			}
		}
	}
	else {
		for (int i = 2; i < n - 1; i++) {
			for (int j = 1; j < i; j++) {
				makeedge(j, i, 1 << (i - 2));
			}
		}
		int x = d - (1 << (n - 3));
		int base_len = (1 << (n - 3));
		for (int i = 0; i < n + 3; i++) {
			if ((x >> i) % 2 == 1) {
				makeedge(i + 2, n - 1, base_len - (1 << i));
				base_len += 1 << i;
			}
		}
	}
	for (int i = 1; i < n; i++) {
		makeedge(i, n, pl);
	}
	printf("YES\n");
	printf("%d %d\n", n, m);
	for (int i = 0; i < m; i++) {
		printf("%d %d %d\n", edge[i][0], edge[i][1], edge[i][2]);
	}
	return 0;
}