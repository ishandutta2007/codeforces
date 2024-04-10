#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXP = MAXN * 5;

int ls[MAXP], rs[MAXP], val[MAXP], f[MAXP], is[MAXP], lef[MAXP], rig[MAXP], pcnt;
int new_Node(int k)
{
	int u = ++pcnt;
	ls[u] = rs[u] = 0; val[u] = k;
	f[u] = 0; is[u] = 0;
	return u;
}
int copy_Node(int u)
{
	int v = ++pcnt;
	ls[v] = ls[u]; rs[v] = rs[u]; val[v] = val[u];
	f[v] = f[u]; is[v] = is[u];
	return v;
}
void push_up(int u)
{
	f[u] = f[ls[u]] + f[rs[u]];
	lef[u] = ls[u]? lef[ls[u]]: u;
	rig[u] = rs[u]? rig[rs[u]]: u;
	if(!is[ls[u]] || !is[rs[u]]) is[u] = 1, ++f[u];
	else is[u] = 0;
}
void build(int u)
{
	if(!u) return;
	build(ls[u]); build(rs[u]);
	push_up(u);
}
void merge(int &u,int v)
{
	if(!u){ u = v; return;}
	if(!v) return;
	if(val[u] > val[v])
	{
		u = copy_Node(u);
		merge(rs[u], v);
	}
	else
	{
		swap(u, v);
		u = copy_Node(u);
		swap(ls[u], v);
		merge(ls[u], v);
	}
	push_up(u);
}

int query(int u,int ql,int qr)
{
	if(u == 0) return 0;
	if(ql <= lef[u] && rig[u] <= qr) return u;
	if(qr < lef[u] || rig[u] < ql) return 0;
	
	int res = 0;
	if(ql<u) merge(res, query(ls[u], ql, qr));
	if(ql<=u && u<=qr) merge(res, new_Node(val[u]));
	if(u<qr) merge(res, query(rs[u], ql, qr));
	return res;
}

int a[MAXN], b[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=d; ++i) scanf("%d%d",&a[i],&b[i]);
	{
		int A,B,C,D;
		scanf("%d%d%d%d",&A,&B,&C,&D);
		const int mod = 1e9 + 9;
		for(int i=d+1; i<=n; ++i)
		{
			a[i] = ((ll)A * a[i-1] + B) %mod;
			b[i] = ((ll)C * b[i-1] + D) %mod;
		}
	}
	{
		static int id[MAXN], ta[MAXN], tb[MAXN];
		iota(id+1, id+n+1, 1);
		sort(id+1, id+n+1, [&] (int x,int y){
			return a[x] < a[y];
		});
		for(int i=1; i<=n; ++i)
			ta[i] = a[id[i]], tb[i] = b[id[i]];
		memcpy(a, ta, (n+1)<<2);
		memcpy(b, tb, (n+1)<<2);
	}
	
	static int sta[MAXN], tp = 0;
	for(int i=1; i<=n; ++i)
	{
		while(tp && b[sta[tp]] < b[i]) ls[i] = sta[tp--];
		if(tp) rs[sta[tp]] = i;
		sta[++tp] = i;
	}
	
	int rt = sta[1];
	f[0] = 0; is[0] = 1; pcnt = n;
	for(int i=1; i<=n; ++i) val[i] = b[i];
	build(rt);
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int ql, qr;
		scanf("%d%d",&ql,&qr);
		ql = lower_bound(a+1,a+n+1,ql) - a;
		qr = upper_bound(a+1,a+n+1,qr) - a - 1;
		if(ql > qr)
		{
			printf("0\n");
			continue;
		}
		pcnt = n;
		int res = query(rt, ql, qr);
		printf("%d\n",f[res]);
	}
	return 0;
}