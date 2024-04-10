#include<stdio.h>
int n;
int edge[100100][2];
int a[100100];
int cnt[100100];
int scnt;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &edge[i][0], &edge[i][1]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[edge[i][0]] != a[edge[i][1]]) {
			cnt[edge[i][0]]++;
			cnt[edge[i][1]]++;
			scnt++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == scnt) {
			printf("YES\n");
			printf("%d", i);
			return 0;
		}
	}
	printf("NO");
	return 0;
}