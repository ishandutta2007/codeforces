#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <queue>
#define maxn 60005
#define ll long long
using namespace std;
int idcnt = 1;

struct edge
{
	int u, v, c;
	edge *next;
	edge *rev; 
}pool[maxn * 200], *h[maxn], *th[maxn];
int egcnt = 0;
void addtedge(int u, int v, int id)
{
	edge *new1 = &pool[egcnt++];
	new1->u = u, new1->v = v, new1->c = id;
	new1->next = th[u], th[u] = new1;
}
void addedge(int u, int v, int c)
{
	edge *new1 = &pool[egcnt++];
	new1->u = u, new1->v = v, new1->c = c, new1->next = h[u], h[u] = new1;
	edge *new2 = &pool[egcnt++];
	new2->u = v, new2->v = u, new2->c = 0, new2->next = h[v], h[v] = new2;
	new1->rev = new2, new2->rev = new1;
}
struct ST
{
	int id;
	int l, r;
	ST *ch[2];
}p[maxn << 2], *root;
int stcnt = 0;
int top[maxn], fa[maxn], size[maxn], dep[maxn], son[maxn], w[maxn]; // 0 : citizen 1 : guardian 
int bk[maxn], fid[maxn];
int dfn = 0;
void dfs1(int a)
{
	size[a] = 1, son[a] = 0;
	for(edge *p = th[a]; p; p = p->next)
	{
		if(p->v == fa[a]) continue;
		dep[p->v] = dep[a] + 1, fa[p->v] = a, fid[p->v] = p->c, dfs1(p->v); 
		size[a] += size[p->v];
		if(size[p->v] > size[son[a]]) son[a] = p->v;
	}
}
void dfs2(int a)
{
	w[a] = ++dfn;
	bk[w[a]] = a;
	if(son[a]) top[son[a]] = top[a], dfs2(son[a]);
	for(edge *p = th[a]; p; p = p->next)
	{
		if(p->v == fa[a] || p->v == son[a]) continue;
		top[p->v] = p->v, dfs2(p->v);
	}
}
ll inf = 2147483647;
int meg[maxn];
int s, t;
void bdtree(ST *a, int l, int r)
{
	a->l = l, a->r = r, a->id = idcnt++;
	if(l == r) 
	{
		addedge(a->id, t, 1);
		meg[a->id] = fid[bk[l]];
		return;
	}
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r);
	addedge(a->id, a->ch[0]->id, inf), addedge(a->id, a->ch[1]->id, inf);
}
void add(int id, ST *a, int l, int r)
{
	// 1 : id - a->id
	// 0 : a->id - id
	if(l > r) return;
	if(a->l == l && a->r == r)
	{
		addedge(id, a->id, inf);
		return;
	}
	int mid = (a->l + a->r) >> 1;
	if(r <= mid) add(id, a->ch[0], l, r);
	else if(l > mid) add(id, a->ch[1], l, r);
	else add(id, a->ch[0], l, mid), add(id, a->ch[1], mid + 1, r);
}
int q[maxn], level[maxn], fr = 0, ed = 0;
void bfs()
{
	memset(level, -1, sizeof(level));
	fr = ed = 0;
	level[s] = 0, q[ed++] = s;
	while(fr < ed)
	{
		for(edge *p = h[q[fr]]; p; p = p->next)
		{
			if(!p->c) continue;
			if(level[p->v] != -1) continue;
			level[p->v] = level[q[fr]] + 1, q[ed++] = p->v;
		}
		fr++;
	}
}
int dfs(int a, int fl)
{
	if(!fl) return 0;
	if(a == t) return fl;
	int nflow = 0;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(!p->c || level[p->v] != level[a] + 1) continue;
		int nf = dfs(p->v, min(fl - nflow, p->c));
		nflow += nf;
		p->c -= nf, p->rev->c += nf;
	//	if(!p->c) cout<<"CUT"<<a<<" "<<p->v<<endl;
	}
	if(!nflow) level[a] = -1;
	return nflow;
}
int dinic()
{
	int ans = 0;
	while(1)
	{
		bfs();
		int nans = dfs(s, inf);
		ans += nans;
		if(!nans) return ans;
	}
}
void add(int a, int b, int id)
{
	int x = top[a], y = top[b];
	if(dep[x] < dep[y]) swap(x, y), swap(a, b);
	while(x != y)
	{
		if(dep[x] < dep[y]) swap(x, y), swap(a, b);
		add(id, root, w[top[a]], w[a]), a = fa[top[a]], x = top[a];
	}
	if(dep[a] < dep[b]) swap(a, b);
	add(id, root, w[b] + 1, w[a]);
}
int bg[maxn], pled[maxn];
short mc[maxn]; 
int otp[maxn], tp = 0;
bool out[maxn];
void otps(int x)
{
	out[x] = 1;
	if(meg[x]) otp[tp++] = meg[x];
	for(edge *p = h[x]; p; p = p->next)
	{
		if(!p->c) continue;
		if(out[p->v]) continue;
		otps(p->v);
	}
}
int main()
{
	s = idcnt++, t = idcnt++;
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addtedge(u, v, i), addtedge(v, u, i);
	}	

	for(int i = 1; i <= m; i++)
		scanf("%d%d", &bg[i], &pled[i]);
	
	dep[1] = 1, top[1] = 1;
	dfs1(1), dfs2(1);
	root = &p[stcnt++];
	bdtree(root, 1, n);
	
	for(int i = 1; i <= m; i++)
	{
		int n1 = idcnt++;
		mc[n1] = i;
	//	cout<<"MC"<<n1<<" "<<i<<endl;
		addedge(s, n1, 1);
		add(bg[i], pled[i], n1);
	}
	printf("%d\n", dinic());
	memset(out, 0, sizeof(out));
	
	otps(s);
	tp = 0;
	for(int i = 1; i < idcnt; i++)
		if(!out[i] && mc[i]) otp[tp++] = mc[i];
	printf("%d ", tp);
	while(tp) printf("%d ", otp[tp - 1]), tp--;
	printf("\n");
	memset(out, 0, sizeof(out));
	
	otps(s);
	printf("%d ", tp);
	while(tp) printf("%d ", otp[tp - 1]), tp--;
	// t  mc 
	return 0;
 }