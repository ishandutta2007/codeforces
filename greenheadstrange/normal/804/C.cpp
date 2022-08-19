#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 300005
using namespace std;
struct edge
{
	int u, v;
	edge *next;
}pool[maxn << 3], *h[maxn], *ch[maxn];
int cnt = 0;
void addedge(int u, int v)
{
 	edge *new1 = &pool[cnt++];
 	new1->u = u, new1->v = v, new1->next = h[u], h[u] = new1;
}
void addc(int u, int c)
{
	edge *new1 = &pool[cnt++];
	new1->u = u, new1->v = c, new1->next = ch[u], ch[u] = new1;
}
int mx = 0, mxpl = 0;
int c[maxn];
bool hv[maxn];
int hvcnt = 0;
int q[maxn];
void dfs(int a, int fa)
{
	for(edge *p = ch[a]; p; p = p->next)
		q[hvcnt++] = p->v, hv[c[p->v]] = 1;
	int npl = 1;
	while(hv[npl]) npl++;
	for(edge *p = ch[a]; p; p = p->next)
	{
		if(c[p->v]) continue;
		c[p->v] = npl, hv[npl] = 1;
		while(hv[npl]) npl++;
	}
	while(hvcnt) hv[c[q[hvcnt - 1]]] = 0, hvcnt--;
	for(edge *p = h[a]; p; p = p->next)
		if(p->v != fa) dfs(p->v, a);
} 
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		int s;
		scanf("%d", &s);
		if(s > mx) mx = s, mxpl = i;
		for(int j = 1; j <= s; j++)
		{
			int c;
			scanf("%d", &c);
			addc(i, c);
		}
	}
	for(int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v), addedge(v, u);
	}
	if(!mx) mx = 1;
	printf("%d\n", mx);
	dfs(mxpl, -1);
	for(int i = 1; i <= m; i++)
	{
		if(!c[i]) c[i] = 1;
		printf("%d ", c[i]);
	}
	return 0;
}