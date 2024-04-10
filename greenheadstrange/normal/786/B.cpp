#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <queue>
#define maxn 400005
#define ll long long
using namespace std;
int idcnt = 1;

struct edge
{
	int u, v, len;
	edge *next;
}pool[maxn * 20], *h[maxn];
int egcnt = 0;
void addedge(int u, int v, int l)
{
//	cout<<"ADDEDGE"<<u<<" "<<v<<" "<<l<<endl;
	edge *new1 = &pool[egcnt++];
	new1->u = u, new1->v = v, new1->len = l, new1->next = h[u], h[u] = new1;
}

struct ST
{
	int id, revid;
	int l, r;
	ST *ch[2];
}p[maxn << 2], *root;
int stcnt = 0;
int id[maxn];
void bdtree(ST *a, int l, int r)
{
	a->l = l, a->r = r, a->id = idcnt++;
	if(l == r) 
	{
		id[l] = a->id, a->revid = a->id;
	//	cout<<"ID"<<l<<" "<<a->id<<endl;
		return;
	}
	a->revid = idcnt++;
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r);
	addedge(a->id, a->ch[0]->id, 0), addedge(a->id, a->ch[1]->id, 0);
	addedge(a->ch[0]->revid, a->revid, 0), addedge(a->ch[1]->revid, a->revid, 0);
}
void add(int id, ST *a, int l, int r, int t)
{
	// 1 : id - a->id
	// 0 : a->id - id
	if(a->l == l && a->r == r)
	{
		if(t) addedge(id, a->id, 0);
		else addedge(a->revid, id, 0);
		return;
	}
	int mid = (a->l + a->r) >> 1;
	if(r <= mid) add(id, a->ch[0], l, r, t);
	else if(l > mid) add(id, a->ch[1], l, r, t);
	else add(id, a->ch[0], l, mid, t), add(id, a->ch[1], mid + 1, r, t);
}
ll inf = 2147483647;
ll dis[maxn];
int s;
bool ch[maxn];

struct th
{
	int id;
	ll num;
	bool operator < (const th &a)const
	{
		return num > a.num;
	}
};
priority_queue <th> q;
void solve()
{
	inf *= 1000000;
	for(int i = 0; i < maxn; i++)
		dis[i] = inf, ch[i] = 0;
	dis[s] = 0;
	th new1;
	new1.id = s, new1.num = dis[s];
	q.push(new1);
	while(!q.empty())
	{
		new1 = q.top(), q.pop();
		if(ch[new1.id]) continue;
		ch[new1.id] = 1;
		for(edge *p = h[new1.id]; p; p = p->next)
		{
			ll ndis = new1.num + p->len;
			if(dis[p->v] > ndis)
			{
				dis[p->v] = ndis;
				th n1;
				n1.id = p->v, n1.num = dis[p->v], q.push(n1);		
			}
		}
	}
}

int main()
{
	int n, q;
	scanf("%d%d%d", &n, &q, &s);
	root = &p[stcnt++];
	bdtree(root, 1, n);
	s = id[s];
	for(int i = 0; i < q; i++)
	{
		int tp;
		scanf("%d", &tp);
		int v, l, r, w;
		if(tp == 1)
		{
			scanf("%d%d%d", &v, &l, &w);
			addedge(id[v], id[l], w);
		}
		else
		{
			scanf("%d%d%d%d", &v, &l, &r, &w);
			int n1 = idcnt++;
			if(tp == 2)
				addedge(id[v], n1, w),
				add(n1, root, l, r, 1);
			else addedge(n1, id[v], w), 
				add(n1, root, l, r, 0);
		} 
	}
	solve();
	for(int i = 1; i <= n; i++)
		if(dis[id[i]] == inf) printf("-1 ");
		else printf("%I64d ", dis[id[i]]);
	return 0;
 }