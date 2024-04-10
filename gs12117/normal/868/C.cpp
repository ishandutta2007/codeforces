#include<cstdio>
int n, m;
int a[100100][5];
int cnt[16];
int main() {
	scanf("%d%d", &n, &m);
	int flag = 0;
	for (int i = 0; i < n; i++) {
		int tcnt = 0;
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			tcnt += a[i][j] << j;
		}
		cnt[tcnt]++;
		for (int j = 0; j < 16; j++) {
			if ((j&tcnt) == 0 && cnt[j]) {
				flag = 1;
			}
		}
	}
	if (flag) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}