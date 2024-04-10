#include <iostream>
#include <cstring>
#include <cstdio>
#define maxn 35005
using namespace std;
int ldp[maxn], ndp[maxn];
struct ST
{
	int l, r;
	int mxs, lz;
	ST *ch[2];
}pool[maxn << 2], *root;
int cnt = 0;
void update(ST *a)
{
	a->mxs = max(a->ch[1]->mxs, a->ch[0]->mxs);
}
void bdtree(ST *a, int l, int r)
{
	a->l = l, a->r = r, a->lz = 0;
	if(l == r) 
	{
		a->mxs = ldp[l + 1] + l;
		return ;
	}
	int mid = (l + r) >> 1;
	a->ch[0] = &pool[cnt++], a->ch[1] = &pool[cnt++];
	bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r);
	update(a);
}
void actlz(ST *a, int lz)
{
	a->lz += lz, a->mxs += lz;
}
void pushdown(ST *a)
{
	if(!a->lz) return;
	actlz(a->ch[0], a->lz), actlz(a->ch[1], a->lz), a->lz = 0; 
}
void change(ST *a, int l, int r, int lz)
{
	if(a->l == l && a->r == r)
	{
		actlz(a, lz);
		return;
	}
	pushdown(a);
	int mid = (a->l + a->r) >> 1;
	if(r <= mid) change(a->ch[0], l, r, lz);
	else if(l > mid) change(a->ch[1], l, r, lz);
	else change(a->ch[0], l, mid, lz), change(a->ch[1], mid + 1, r, lz);
	update(a);
}
int query(ST *a, int l, int r)
{
	if(a->l == l && a->r == r)
		return a->mxs;
	pushdown(a);
	int mid = (a->l + a->r) >> 1;
	if(r <= mid) return query(a->ch[0], l, r);
	else if(l > mid) return query(a->ch[1], l, r);
	else return max(query(a->ch[0], l, mid), query(a->ch[1], mid + 1, r));
}
int n, k, a[maxn];
int fpl[maxn];
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= k; i++)
	{
		cnt = 0;
		root = &pool[cnt++];
		bdtree(root, 1, n);
		for(int j = 1; j <= n; j++) 
			fpl[j] = n + 1;
		for(int j = n; j >= 1; j--)
		{
			if(fpl[a[j]] != n + 1) change(root, fpl[a[j]], n, -1);
			ndp[j] = query(root, j, n) - j + 1;
			fpl[a[j]] = j;
		}
		for(int j = 1; j <= n; j++) 
			ldp[j] = ndp[j];
	}
	printf("%d\n", ldp[1]);
	return 0;
 }