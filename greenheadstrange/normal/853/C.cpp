#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
#define maxn 200005
using namespace std;
struct ST
{
	ST *ch[2];
	int sz;
	int l, r;
}pool[maxn * 50], *root[maxn];
void copy(ST *a, ST *b, int l, int r)
{
	a->l = l, a->r = r, a->sz = 0, a->ch[0] = a->ch[1] = NULL;
	if(b) a->sz = b->sz, a->ch[0] = b->ch[0], a->ch[1] = b->ch[1];
}
int cnt = 0;
void ins(ST *a, int pl)
{		
	a->sz++;
	if(a->l == a->r) 
		return;
	int mid = (a->l + a->r) >> 1;
	ST *n1 = &pool[cnt++];
	if(pl <= mid) copy(n1, a->ch[0], a->l, mid), a->ch[0] = n1;
	else copy(n1, a->ch[1], mid + 1, a->r), a->ch[1] = n1;
	ins(n1, pl);
}
int q(ST *a, int l, int r)
{
	if(!a) return 0;
	if(r < l) return 0;
	if(a->l == l && a->r == r) return a->sz;
	int mid = (a->l + a->r) >> 1;
	if(r <= mid) return q(a->ch[0], l, r);
	else if(l > mid) return q(a->ch[1], l, r);
	else return q(a->ch[0], l, mid) + q(a->ch[1], mid + 1, r);
}
int ns[maxn];
ll c(ll a){return a * (a - 1) / 2;}
int main()
{
	int n, qs;
	scanf("%d%d", &n, &qs);
	for(int i = 1; i <= n; i++)
	{
		int p;
		scanf("%d", &p);
		p = n + 1 - p;
		ns[p] = i;
	}
	for(int i = 1; i <= n; i++)
		root[i] = &pool[cnt++], 
		copy(root[i], root[i - 1], 1, n), 
		ins(root[i], ns[i]);
	for(int i = 1; i <= qs; i++)
	{
		int l, r, d, u;
		scanf("%d%d%d%d", &l, &d, &r, &u);
		d = n + 1 - d;
		u = n + 1 - u;
		ll ans = 0;
		ans = c(n) - (c(l - 1) + c(n - r) + c(u - 1) + c(n - d));
		ans += c(q(root[u - 1], 1, l - 1)) + c(q(root[u - 1], r + 1, n));
		ans += c(q(root[n], 1, l - 1) - q(root[d], 1, l - 1));
		ans += c(q(root[n], r + 1, n) - q(root[d], r + 1, n)); 
		printf("%I64d\n", ans);
	}
	return 0;
}