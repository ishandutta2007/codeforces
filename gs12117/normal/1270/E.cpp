#include<cstdio>
int n;
int loc[1010][2];
long long int dist[1010];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &loc[i][0], &loc[i][1]);
	}
	for (int i = 0; i < n; i++) {
		dist[i] = ((long long int)loc[i][0] - loc[0][0])*((long long int)loc[i][0] - loc[0][0]) + ((long long int)loc[i][1] - loc[0][1])*((long long int)loc[i][1] - loc[0][1]);
	}
	for (int i = 0;; i++) {
		int flag = 0;
		for (int j = 0; j < n; j++) {
			if (dist[j] % 2 == 1)flag = 1;
		}
		if (flag == 1)break;
		for (int j = 0; j < n; j++) {
			dist[j] /= 2;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (dist[i] % 2 == 1)cnt++;
	}
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++) {
		if (dist[i] % 2 == 1)printf("%d ", i + 1);
	}
	return 0;
}