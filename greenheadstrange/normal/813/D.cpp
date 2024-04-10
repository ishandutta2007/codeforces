#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 200005
using namespace std;
struct edge
{
	int u, v, w, c;
	edge *next;
	edge *rev;
}pool[maxn], *h[maxn];
int cnt = 0;
void addedge(int u, int v, int w, int c)
{	// c : cost w : flow
//	cout<<"ADE"<<u<<" "<<v<<" "<<w<<" "<<c<<endl;
	edge *new1 = &pool[cnt++];
	edge *new2 = &pool[cnt++];
	new1->u = u, new1->v = v, new1->w = w, new1->c = c;
	new2->u = v, new2->v = u, new2->w = 0, new2->c = -c;
	new1->next = h[u], h[u] = new1;
	new2->next = h[v], h[v] = new2;
	new1->rev = new2, new2->rev = new1;
}
int s, t, dis[maxn];
int q[maxn * 200], fr, ed, inq[maxn];
edge *pre[maxn];
int spfa()
{
//	cout<<s<<" "<<t<<endl;
	int ans = 0;
	while(1)
	{
		fr = ed = 0;
		memset(inq, 0, sizeof(inq));
		memset(dis, -1, sizeof(dis));
		q[ed++] = s, dis[s] = 0, inq[s] = 1;
		while(fr < ed)
		{
			for(edge *p = h[q[fr]]; p; p = p->next)
			{
				if(!p->w) continue;
				int ndis = p->c + dis[q[fr]];
				if(ndis <= dis[p->v]) continue;
				dis[p->v] = ndis, pre[p->v] = p;
				if(!inq[p->v]) inq[p->v] = 1, q[ed++] = p->v;
			}
			inq[q[fr]] = 0;
			fr++;
		} 
		if(dis[t] == -1) return ans;
		ans += dis[t];
		int npl = t;
		while(npl != s)
			pre[npl]->w--, pre[npl]->rev->w++, 
			npl = pre[npl]->u;
	}
}
int x[maxn];
int nst[maxn], mst[maxn], in[maxn], out[maxn]; // num mod
int main()
{
//	freopen("cut.in", "r", stdin);
	int n, k = 2;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &x[i]);
	int idcnt = 0;
	s = idcnt++, t = idcnt++;
	for(int i = 1; i <= n; i++)
		nst[i] = idcnt++, mst[i] = idcnt++, 
		in[i] = idcnt++, out[i] = idcnt++, 
		addedge(mst[i], in[i], 1, 0), 
		addedge(nst[i], in[i], 1, 0), 
		addedge(in[i], out[i], 1, 1), 
		addedge(out[i], t, 1, 0);
	
	for(int i = 1; i <= n; i++) // add st
	{
		for(int j = i + 1; j <= n; j++)
			if(x[j] % 7 == x[i] % 7) 
			{
				addedge(mst[i], mst[j], 1000, 0);
				break;
			}
		for(int j = i + 1; j <= n; j++)
			if(x[j] == x[i])
			{
				addedge(nst[i], nst[j], 1000, 0);
				break;
			}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
			if(x[j] == x[i] + 1)
			{
				addedge(out[i], nst[j], 1, 0);
				break;
			}
		for(int j = i + 1; j <= n; j++)
			if(x[j] == x[i] - 1)
			{
				addedge(out[i], nst[j], 1, 0);
				break;
			}
		for(int j = i + 1; j <= n; j++)
			if(x[j] % 7 == x[i] % 7)
			{
				addedge(out[i], mst[j], 1, 0);
				break;
			}
	}
	int ns = idcnt++;
	addedge(s, ns, k, 0);
	for(int i = 1; i <= n; i++)
		addedge(ns, in[i], 1, 0);
	printf("%d\n", spfa());
	return 0;
}