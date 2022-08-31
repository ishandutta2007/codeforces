#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define maxn 300005
using namespace std;
struct edge
{
	int u, v, id;
	edge *next;
}pool[maxn << 1], *h[maxn];
struct pa
{
	int x, y, id;
	bool operator < (const pa & a)const
	{
		if(x != a.x) return x < a.x;
		return y < a.y; 
	}
}eg[maxn];
int cnt = 0;
void addedge(int u, int v, int id)
{
	edge *new1 = &pool[cnt++];
	new1->u = u, new1->v = v, new1->id = id, new1->next = h[u], h[u] = new1;
}
int n, m;
int dp[2][maxn];
int d[maxn];
int dep[maxn];
void dfs(int a, int fa)
{
//	cout<<"DFS"<<a<<" "<<fa<<endl;
	dp[0][a] = dp[1][a] = 0;
	int lks = 0;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(dep[p->v]) continue;
		dep[p->v] = dep[a] + 1;
		dfs(p->v, a);
		if(!dp[0][p->v] && !dp[1][p->v]) 
		{
			dp[0][a] = dp[1][a] = 0; 
			return;
		}
		if(dp[0][p->v] && dp[1][p->v])
			dp[0][a] = dp[1][a] = 1;
		else 
			if(dp[1][p->v]) lks++, lks &= 1;
	}
	if(d[a] == -1) dp[0][a] = dp[1][a] = 1;
	else dp[d[a] ^ lks][a] = 1;

}
int otp[maxn], top = 0;

void solve(int a, int tp)
{	
	int lks = 0, ns = 0, ntp = 0;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(dep[p->v] != dep[a] + 1) continue;
		if(dp[0][p->v] && dp[1][p->v])
			ns = p->v;
		else if(dp[1][p->v]) lks++;
	}
	lks &= 1;
	if(d[a] != -1) 
		ntp = d[a] ^ tp ^ lks;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(dep[p->v] != dep[a] + 1) continue;
		int t = ntp;
		if(p->v != ns)
			if(dp[0][p->v]) t = 0;
			else t = 1;
		if(t) otp[top++] = p->id;
		solve(p->v, t);
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &d[i]);
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if(u > v) swap(u, v);
		eg[i].x = u, eg[i].y = v, eg[i].id = i;
	}	
	sort(eg + 1, eg + m + 1);
	for(int i = 1; i <= m; i++)
		if(i == 1 || eg[i - 1] < eg[i])
			addedge(eg[i].x, eg[i].y, eg[i].id), 
			addedge(eg[i].y, eg[i].x, eg[i].id);	

//	cout<<"DFS"<<endl;
	dep[1] = 1;
	dfs(1, 0);
	if(!dp[0][1]) printf("-1\n");
	else 
	{
		solve(1, 0);
		printf("%d\n", top);
		for(int i = 0; i < top; i++)
			printf("%d\n", otp[i]);
	}
	return 0;
}