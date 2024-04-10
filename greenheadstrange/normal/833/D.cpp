#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath> 
#include <algorithm>
#define maxn 100005
#define mod 1000000007
#define ll long long
using namespace std;
ll ksm(ll a, ll b)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns *= ns, ns %= mod;
	if(b & 1) ns *= a, ns %= mod;
	return ns;
}
struct edge
{
	int u, v, c;
	ll w;
	bool flag;
	edge *rev;
	edge *next;
}pool[maxn << 2], *h[maxn];
int cnt = 0;
void addedge(int u, int v, int w, int c)
{
	edge *new1 = &pool[cnt++];
	new1->u = u, new1->v = v, new1->w = w, new1->c = c, new1->flag = 1, new1->next = h[u], h[u] = new1;
	edge *new2 = &pool[cnt++];
	new2->u = v, new2->v = u, new2->w = w, new2->c = c, new2->flag = 1, new2->next = h[v], h[v] = new2;
	new1->rev = new2, new2->rev = new1;
}
int mxpl = -1, mxs = maxn;
int size[maxn];
void getzx(int a, int fa, int asize)
{
	size[a] = 1;
	int nmx = 0;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(!p->flag) continue;
		if(p->v == fa) continue;
		getzx(p->v, a, asize), size[a] += size[p->v], nmx = max(nmx, size[p->v]);
	}	
	int ns = max(nmx, asize - size[a]);
	if(ns < mxs) mxs = ns, mxpl = a;
} 

int lowbit(int x)
{
	return x & (-x); 
}
const int pls = maxn * 2;
struct bit1
{
	int d[maxn << 2];
	int chq[maxn * 20], ed;
	bit1()
	{
		ed = 0;
		for(int i = 0; i < (maxn << 2); i++) d[i] = 0;
	}
	void init()
	{
		while(ed) d[chq[ed - 1]] = 0, ed--;
 	}
 	void ch(int pl, int num)
 	{
 		pl += pls;
 		while(pl < (maxn << 2))
 			d[pl] += num, chq[ed++] = pl, pl += lowbit(pl);
	}
	int query(int pl)
	{
		pl += pls;
		int ans = 0;
		while(pl)
			ans += d[pl], pl -= lowbit(pl);
		return ans;
	}
}plbit[2];

struct bit2
{
	ll d[maxn << 2];
	int chq[maxn * 20], ed;
	bit2()
	{
		ed = 0;
		for(int i = 0; i < (maxn << 2); i++) d[i] = 1;
	}
	void init()
	{
		while(ed) d[chq[ed - 1]] = 1, ed--;
 	}
 	void ch(int pl, int num)
 	{
 	//	cout<<"CHANGE"<<pl<<" "<<num<<endl;
 		pl += pls;
 		while(pl < (maxn << 2))
 			d[pl] *= num, d[pl] %= mod, chq[ed++] = pl, pl += lowbit(pl);
	}
	ll query(int pl)
	{
		pl += pls;
		ll ans = 1;
		while(pl)
			ans *= d[pl], ans %= mod, pl -= lowbit(pl);
		return ans;
	}
}mulbit[2];

int ed = 0, q[maxn][3], num[maxn][2];
ll ans = 1;
void dfs(int a, int fa, ll mt)
{
	q[ed][0] = num[a][0], q[ed][1] = num[a][1], q[ed][2] = mt, ed++;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(!p->flag) continue;
		if(p->v == fa) continue;
		num[p->v][0] = num[a][0], num[p->v][1] = num[a][1], num[p->v][p->c]++;
		dfs(p->v, a, mt * p->w % mod);
	}
}
ll bk(ll a){return ksm(a, mod - 2);}
void work(int a, int asize)
{
	for(int i = 0; i < 2; i++)
		plbit[i].init(), mulbit[i].init();
	ll nsize = 1, nl = 1;
	for(int j = 0; j < 2; j++)
		plbit[j].ch(0, 1), mulbit[j].ch(0, 1);
	for(edge *p = h[a]; p; p = p->next)
	{
		if(!p->flag) continue;
		ed = 0;
		num[p->v][0] = num[p->v][1] = 0, num[p->v][p->c]++;
		dfs(p->v, a, p->w);
		for(int i = 0; i < ed; i++)
		{
			ans *= ksm(q[i][2], nsize), ans %= mod; 
			ans *= nl, ans %= mod;
		}
		for(int i = 0; i < ed; i++)
			nl *= q[i][2], nl %= mod, nsize++;
		for(int i = 0; i < ed; i++)
			for(int j = 0; j < 2; j++)
				ans *= bk(ksm(q[i][2], plbit[j].query(q[i][j] - 2 * q[i][!j] - 1))), 
				ans %= mod,
				ans *= bk(mulbit[j].query(q[i][j] - 2 * q[i][!j] - 1)),
				ans %= mod;
			
		for(int i = 0; i < ed; i++)
			for(int j = 0; j < 2; j++)
				plbit[j].ch(2 * q[i][!j] - q[i][j], 1), 
				mulbit[j].ch(2 * q[i][!j] - q[i][j], q[i][2]);
	}
	getzx(a, -1, asize);
	for(edge *p = h[a]; p; p = p->next)
	{
		if(!p->flag) continue; 
		p->flag = p->rev->flag = 0;
		mxpl = -1, mxs = maxn;
		getzx(p->v, -1, size[p->v]);
		work(mxpl, size[p->v]);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int u, v, w, c;
		scanf("%d%d%d%d", &u, &v, &w, &c);
		addedge(u, v, w, c);
	}
	work(1, n);
	printf("%I64d\n", ans);
	return 0;
}