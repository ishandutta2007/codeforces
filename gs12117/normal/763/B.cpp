#include<stdio.h>
int n;
int rect[500100][4];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &rect[i][0], &rect[i][1], &rect[i][2], &rect[i][3]);
	}
	printf("YES\n");
	for (int i = 0; i < n; i++) {
		int x = rect[i][0];
		if (x < 0)x = -x;
		int y = rect[i][1];
		if (y < 0)y = -y;
		printf("%d\n", (x % 2) * 2 + y % 2 + 1);
	}
	return 0;
}