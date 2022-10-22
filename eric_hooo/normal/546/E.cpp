#include <bits/stdc++.h>
using namespace std;

int a[210], b[210];
int g[210][210];
int vis[210], path[210];
queue <int> q;

int bfs(int s, int t){
	for (int i = 0; i <= t; i++){
		vis[i] = 0;
	}
	while (!q.empty()) q.pop();
	q.push(s), vis[s] = 1;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int i = 0; i <= t; i++){
			if (vis[i] || g[u][i] <= 0) continue;
			vis[i] = 1, path[i] = u;
			if (i == t) break;
			q.push(i);
		}
	}
	if (!vis[t]) return 0;
	int now = t, minj = 0x3f3f3f3f;
	while (now != s){
		int last = path[now];
		minj = min(minj, g[last][now]);
		now = last;
	}
	now = t;
	while (now != s){
		int last = path[now];
		g[last][now] -= minj;
		g[now][last] += minj;
		now = last;
	}
	return minj;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int s = 0, t = n + n + 1;
	int sum = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 1; i <= n; i++){
		scanf("%d", &b[i]);
		sum -= b[i];
	}
	if (sum != 0){
		printf("NO\n");
		return 0;
	}
	for (int i = 0; i < m; i++){
		int u, v; scanf("%d%d", &u, &v);
		g[u][v + n] = a[u], g[v][u + n] = a[v];
	}
	for (int i = 1; i <= n; i++){
		g[i][i + n] = a[i];
		g[s][i] = a[i];
		g[i + n][t] = b[i];
	}
	while (bfs(s, t));
	for (int i = 1; i <= n; i++){
		if (g[i + n][t] != 0){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			printf("%d ", g[j + n][i]);
		}
		printf("\n");
	}
	return 0;
}