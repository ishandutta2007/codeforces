#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 600005
#define ll long long
using namespace std;
int mxs[maxn], mxpl[maxn];
int num[maxn], pre[maxn], ch[maxn][2], rev[maxn];
void pushdown(int a)
{
	if(rev[a])	
		swap(ch[a][0], ch[a][1]),
		rev[ch[a][0]] ^= 1, 
		rev[ch[a][1]] ^= 1, 
		rev[a] = 0;
} 
void upd(int a)
{
	mxs[a] = num[a], mxpl[a] = a;
	for(int i = 0; i < 2; i++)
		if(ch[a][i] && mxs[ch[a][i]] > mxs[a])
			mxs[a] = mxs[ch[a][i]], mxpl[a] = mxpl[ch[a][i]];
}
bool isroot(int x)
{
	return ch[pre[x]][1] != x && ch[pre[x]][0] != x;
}
void rotate(int a)
{
	int fa = pre[a], tp = ch[fa][1] == a;
	int son = ch[a][!tp], gfa = pre[fa];
	if(!isroot(fa)) ch[gfa][ch[gfa][1] == fa] = a;
	pre[a] = gfa;
	ch[a][!tp] = fa, 
	pre[fa] = a;
	ch[fa][tp] = son;
	if(son) pre[son] = fa;
	upd(fa), upd(a);
}
int st[maxn], top = 0;
void push(int x)
{
	st[top++] = x;
	if(isroot(x)) return;
	push(pre[x]);
}
void splay(int x)
{
	top = 0;
	push(x);
	for(int i = top - 1; i >= 0; i--)
		pushdown(st[i]);
	while(!isroot(x))
	{
		if(isroot(pre[x]))
			rotate(x);
		else
		{
			int fa = pre[x], gfa = pre[fa];
			int apl = ch[fa][1] == x, fapl = ch[gfa][1] == fa;
			if(apl == fapl) rotate(fa), rotate(x);
			else rotate(x), rotate(x);
		}
	}
}
void access(int a)
{
	for(int x = a, t = 0; x; t = x, x = pre[x])
		splay(x), ch[x][1] = t, upd(x);
	splay(a);
}
void makeroot(int a)
{
	access(a), rev[a] ^= 1;
}
void link(int a, int b)
{
	makeroot(a), pre[a] = b;
}
void cut(int a, int b)
{
	makeroot(a), access(b);
	pre[ch[b][0]] = 0, ch[b][0] = 0;
	upd(b);
}
int fr(int a)
{
	pushdown(a);
	if(ch[a][0]) return fr(ch[a][0]);
	return a;
}
int findroot(int a)
{
	access(a);
	return fr(a);
}

int rst[maxn];
struct edge
{
	int u, v, id;
	edge *next;
}p[maxn], *h[maxn];
int egcnt = 0;
void addedge(int u, int v, int id)
{
	edge *n1 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->id = id, n1->next = h[u], h[u] = n1;
}

int q(int x, int y)
{
	makeroot(x), access(y);
	return mxpl[y];
}
bool flag[maxn];
int u[maxn], v[maxn];
struct ST
{
	ST *ch[2];
	ll sum;
	int size;
}stp[maxn * 10], *root[maxn];
int stcnt = 0;
void copy(ST *a, ST *b)
{
	if(b) a->sum = b->sum, a->size = b->size, a->ch[0] = b->ch[0], a->ch[1] = b->ch[1];
}
void ins(ST *a, int pl, int l, int r)
{
	a->sum += pl;
	a->size++;
	int mid = (l + r) >> 1;
	if(l == r) return ;
	ST *n1 = &stp[stcnt++];
	if(pl <= mid)
		copy(n1, a->ch[0]), 
		a->ch[0] = n1, 
		ins(n1, pl, l, mid);
	else 
		copy(n1, a->ch[1]), 
		a->ch[1] = n1, 
		ins(n1, pl, mid + 1, r);
}
ll qsum(ST *a, int l, int r, int ql, int qr)
{
	if(ql > qr) return 0;
	if(!a) return 0;
	if(l == ql && r == qr) return a->sum;
	int mid = (l + r) >> 1;
	if(qr <= mid) return qsum(a->ch[0], l, mid, ql, qr);
	else if(ql > mid) return qsum(a->ch[1], mid + 1, r, ql, qr);
	else return qsum(a->ch[0], l, mid, ql, mid) + qsum(a->ch[1], mid + 1, r, mid + 1, qr);
}
int qsz(ST *a, int l, int r, int ql, int qr)
{
	if(ql > qr) return 0;
	if(!a) return 0;
	if(l == ql && r == qr) return a->size;
	int mid = (l + r) >> 1;
	if(qr <= mid) return qsz(a->ch[0], l, mid, ql, qr);
	else if(ql > mid) return qsz(a->ch[1], mid + 1, r, ql, qr);
	else return qsz(a->ch[0], l, mid, ql, mid) + qsz(a->ch[1], mid + 1, r, mid + 1, qr);
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &u[i], &v[i]);
		addedge(u[i], v[i], i), addedge(v[i], u[i], i);
		num[i + n] = max(u[i], v[i]); 
	}
	int r = n;
	int ncnt = n, neg = 0;
	for(int i = n; i >= 1; i--)
	{
		int nf = findroot(i);
		for(edge *p = h[i]; p; p = p->next)
		{
			if(p->v > r || p->v < i) continue;
			neg++;
			int tf = findroot(p->v);
			if(tf != nf)
			{
				flag[p->id] = 1;
				link(p->v, p->id + n), link(p->id + n, i);
				ncnt--;
			}
			else
			{
				int nmx = q(p->v, i);
				if(num[nmx] > num[p->id + n])
				{
					flag[nmx - n] = 0;
					cut(nmx, u[nmx - n]), cut(nmx, v[nmx - n]), 
					link(i, p->id + n), link(p->id + n, p->v);
					flag[p->id] = 1;
				}
			}
		}
		while(neg > n - ncnt)
		{
			for(edge *p = h[r]; p; p = p->next)
			{
				if(p->v > r || p->v < i) continue;
				neg--;
				if(flag[p->id])
				{
					cut(p->id + n, u[p->id]), 
					cut(p->id + n, v[p->id]),
					ncnt++;
				}
			}
			r--;
		}
		rst[i] = r;
	}
	for(int i = 1; i <= n; i++)
	{
		root[i] = &stp[stcnt++];
		copy(root[i], root[i - 1]);
		ins(root[i], rst[i], 1, n);
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		
		ll nans = r * (ll)(qsz(root[r], 1, n, r + 1, n) - qsz(root[l - 1], 1, n, r + 1, n));
		nans += qsum(root[r], 1, n, 1, r) - qsum(root[l - 1], 1, n, 1, r);
		nans -= (r + l) * (ll)(r - l + 1) / 2;
		nans += r - l + 1;
		printf("%I64d\n", nans);
	}
	return 0;
}