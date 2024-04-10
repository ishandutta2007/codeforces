#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 5005
#define ll long long
using namespace std;
struct edge
{
	int u, v;
	edge *next;
}pool[maxn], *h[maxn];
int cnt = 0;
void addedge(int u, int v)
{
	edge *new1 = &pool[cnt++];
	new1->u = u, new1->v = v, new1->next = h[u], h[u] = new1;
}
ll c[maxn], d[maxn];
ll dp[2][maxn][maxn];
int size[maxn]; // 0 : fa 1 :  
ll ndp[maxn];
const ll inf = 214748360000000;
void dfs(int a)
{
	for(int i = 0; i < maxn; i++)
		dp[0][a][i] = dp[1][a][i] = ndp[i] = inf;
	dp[0][a][0] = 0;
	dp[0][a][1] = c[a],	dp[1][a][0] = c[a] - d[a]; // dp1 :  
	size[a] = 1;
	for(edge *p = h[a]; p; p = p->next)	
	{
		dfs(p->v);
		//solve 0
		for(int i = 0; i < maxn; i++)
			ndp[i] = inf;
		for(int i = 0; i <= size[a]; i++)
			for(int j = 0; j <= size[p->v]; j++)
				ndp[i + j] = min(ndp[i + j], dp[0][a][i] + dp[0][p->v][j]);	
		
		for(int i = 0; i < maxn; i++)
			dp[0][a][i] = min(dp[0][a][i], ndp[i]);
			
		for(int i = 0; i < maxn; i++)
			ndp[i] = inf;
			
		for(int i = 0; i <= size[a]; i++)
			for(int j = 0; j <= size[p->v]; j++)
				ndp[i + j] = min(ndp[i + j], dp[1][a][i] + dp[1][p->v][j]);
			
		for(int i = 0; i < maxn; i++) 
			dp[1][a][i] = min(dp[1][a][i], ndp[i]);
			
		size[a] += size[p->v];
	}
	
	for(int i = maxn - 1; i >= 1; i--)
		dp[1][a][i] = dp[1][a][i - 1];	
		
	for(int i = 0; i <= size[a]; i++)
		dp[1][a][i] = min(dp[1][a][i], dp[0][a][i]);

}
int main()
{
	int n, b;
	scanf("%d%d", &n, &b);
	for(int i = 1; i <= n; i++)
	{
		scanf("%I64d%I64d", &c[i], &d[i]);
		int x;
		if(i >= 2)
			scanf("%d", &x), addedge(x, i);
	}
	dfs(1);
	int ans = 0;
	for(int i = 0; i < maxn; i++)
		if(dp[1][1][i] <= b) ans = i;
	printf("%d\n", ans);
	return 0;
}