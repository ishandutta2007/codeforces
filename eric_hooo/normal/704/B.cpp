#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

int x[5010], a[5010], b[5010], c[5010], d[5010];

int n;

void init(){
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
}

long long dist[5010][5010];
int nxt[5010];

int main(){
	int s, e;
	scanf("%d%d%d", &n, &s, &e);
	init();
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (j < i) dist[i][j] = 1ll * abs(x[i] - x[j]) + c[i] + b[j];
			if (j > i) dist[i][j] = 1ll * abs(x[i] - x[j]) + d[i] + a[j];
		}
	}
	long long res = dist[s][e];
	memset(nxt, -1, sizeof(nxt));
	nxt[s] = e;
	for (int i = 1; i <= n; i++){
		if (i == s || i == e) continue;
		long long cost = dist[s][i] + dist[i][nxt[s]] - dist[s][nxt[s]];
		int pos = s;
		for (int u = nxt[s]; nxt[u] != -1; u = nxt[u]){
			int v = nxt[u];
			long long new_c = dist[u][i] + dist[i][v];
			if (cost > new_c - dist[u][v]) pos = u, cost = new_c - dist[u][v];
		}
		res += cost;
		nxt[i] = nxt[pos], nxt[pos] = i;
		/*
		printf("%d\n", i);
		for (int j = s; j != -1; j = nxt[j]){
			printf("%d ", j);
		}
		printf("\n");
		*/
	}
	printf("%I64d\n", res);
	return 0;
}