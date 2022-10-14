#include <stdio.h>
#include <string.h>

const int N = 200, INF = 100000;

int n, extra, weight[N], first[N], to[N + N], next[N + N], cost[N][N], opt[N][N], best[N][N], sol[N];

void add(int i, int u, int v){
	to[i] = v;
	next[i] = first[u];
	first[u] = i;
}

void dfs(int c[], int p, int u, int x){
	c[u] = weight[x];
	for(int iter = first[u]; iter; iter = next[iter]){
		int v = to[iter];
		if(v != p)
			dfs(c, u, v, x + 1);
	}
}

int min(int a, int b){
	return a < b? a: b;
}

void dp(int p, int u){
	for(int iter = first[u]; iter; iter = next[iter]){
		int v = to[iter];
		if(v != p)
			dp(u, v);
	}
	for(int i = 1; i <= n; ++ i){
		opt[u][i] = cost[u][i];
		for(int iter = first[u]; iter; iter = next[iter]){
			int v = to[iter];
			opt[u][i] += min(opt[v][i], opt[v][best[v][i]] + extra);
		}
	}
	int *f = opt[u], *b = best[u], t;
	for(int i = 1; i <= n; ++ i)
		b[i] = i % n + 1;
	t = 1;
	for(int i = 2; i <= n; ++ i){
		if(f[t] < f[b[i]])
			b[i] = t;
		if(f[i] < f[t])
			t = i;
	}
	t = n;
	for(int i = n - 1; i >= 1; -- i){
		if(f[t] < f[b[i]])
			b[i] = t;
		if(f[i] < f[t])
			t = i;
	}
}

int get(int p, int u, int i){
	sol[u] = i;
	for(int iter = first[u]; iter; iter = next[iter]){
		int v = to[iter];
		if(v != p){
			if(opt[v][i] < opt[v][best[v][i]] + extra)
				get(u, v, i);
			else
				get(u, v, best[v][i]);
		}
	}	
}

int main(){
	scanf("%d%d", &n, &extra);
	weight[0] = 0;
	for(int i = 1; i < n; ++ i)
		scanf("%d", weight + i);
	memset(first, 0, sizeof(first));
	for(int i = 1, a, b; i < n; ++ i){
		scanf("%d%d", &a, &b);
		add(i + i - 1, a, b);
		add(i + i, b, a);
	}
	for(int i = 1; i <= n; ++ i)
		dfs(cost[i], 0, i, 0);
	dp(0, 1);
	int t = 1;
	for(int i = 2; i <= n; ++ i)
		if(opt[1][i] < opt[1][t])
			t = i;
	get(0, 1, t);
	printf("%d\n", opt[1][t] + extra);
	for(int i = 1; i < n; ++ i)
		printf("%d ", sol[i]);
	printf("%d\n", sol[n]);
	return 0;
}