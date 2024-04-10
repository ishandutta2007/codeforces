#include<cstdio>
int n, m;
int aeg[10100][2];
int as[54][54];
int bs[54][54];
int nn;
int el[100100][5];
int en;
int ed[100100];
int dist[100100];
int backe[100100];
int scost;
int ans[54][54];
void puteg(int start, int end, int capa, int cost) {
	el[en][0] = start;
	el[en][1] = end;
	el[en][2] = capa;
	el[en][3] = cost;
	el[en][4] = en + 1;
	en++;
	el[en][0] = end;
	el[en][1] = start;
	el[en][2] = 0;
	el[en][3] = -cost;
	el[en][4] = en - 1;
	en++;
}
void flow() {
	for (int i = 0; i < nn; i++) {
		dist[i] = 999999999;
	}
	dist[0] = 0;
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int i = 0; i < en; i++) {
			if (el[i][2] == 0)continue;
			int rdist = dist[el[i][0]] + el[i][3];
			if (dist[el[i][1]] > rdist) {
				dist[el[i][1]] = rdist;
				backe[el[i][1]] = i;
				flag = 1;
			}
		}
	}
	scost += dist[1];
	int x = 1;
	while (x != 0) {
		int y = backe[x];
		el[y][2] -= 1;
		el[el[y][4]][2] += 1;
		x = el[y][0];
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &aeg[i][0], &aeg[i][1]);
	}
	for (int i = 0; i < m; i++) {
		as[aeg[i][0] - 1][aeg[i][1] - 1] = 1;
	}
	nn = 2 + n + n;
	int p = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			bs[i][j] = nn + p;
			ed[nn + p] = i ^ j;
			puteg(0, nn + p, 1, 0);
			if (as[i][j] == 0) {
				puteg(nn + p, 2 + i, 1, 0);
			}
			if (as[j][i] == 0) {
				puteg(nn + p, 2 + j, 1, 0);
			}
			p++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			puteg(2 + i, 2 + n + j, 1, 0);
		}
	}
	for (int i = 1; i < n; i++) {
		puteg(2 + n + i, 2 + n + i - 1, 10000000, 1);
	}
	puteg(2 + n + 0, 1, 10000000, 0);
	nn += p;
	for (int i = 0; i < p; i++) {
		flow();
	}
	//printf("%d ", scost);
	//printf("%d\n", (n*(n - 1)*(n - 2) - 6 * scost) / 2);
	for (int i = 0; i < en; i++) {
		if (el[i][0] >= 2 + n + n && el[i][1] >= 2 && el[i][1] < 2 + n && el[i][2] == 0) {
			int x = el[i][1] - 2;
			int y = x ^ ed[el[i][0]];
			ans[y][x] = 1;
		}
		//printf("%d %d %d %d %d\n", el[i][0], el[i][1], el[i][2], el[i][3], el[i][4]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}