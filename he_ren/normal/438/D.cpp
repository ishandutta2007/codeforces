#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

inline int max(int a,int b){ return a>b? a:b;}

ll sum[MAXN<<2];
int mx[MAXN<<2];
#define ls(u) ((u)<<1)
#define rs(u) ((u)<<1|1)

inline void push_up(int u)
{
	sum[u] = sum[ls(u)] + sum[rs(u)];
	mx[u] = max(mx[ls(u)], mx[rs(u)]);
}

void build(int u,int l,int r)
{
	if(l==r)
	{
		scanf("%d",&mx[u]);
		sum[u]=mx[u];
		return;
	}
	int mid = (l+r)>>1;
	build(ls(u),l,mid);
	build(rs(u),mid+1,r);
	push_up(u);
}

ll query(int u,int l,int r, int ql,int qr)
{
	if(ql<=l && r<=qr) return sum[u];
	int mid = (l+r)>>1;
	ll res=0;
	if(ql<=mid) res += query(ls(u),l,mid, ql,qr);
	if(mid<qr) res += query(rs(u),mid+1,r, ql,qr);
	return res;
}

void update1(int u,int l,int r, int ql,int qr,int k)//operatoin 2
{
	if(mx[u]<k) return;
	if(l==r)
	{
		sum[u]%=k; mx[u]%=k;
		return;
	}
	int mid = (l+r)>>1;
	if(ql<=mid) update1(ls(u),l,mid, ql,qr,k);
	if(mid<qr) update1(rs(u),mid+1,r, ql,qr,k);
	push_up(u);
}

void update2(int u,int l,int r, int q,int k)//operation 3
{
	if(l==r)
	{
		sum[u]=mx[u]=k;
		return;
	}
	int mid = (l+r)>>1;
	if(q<=mid) update2(ls(u),l,mid, q,k);
	else update2(rs(u),mid+1,r, q,k);
	push_up(u);
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	build(1,1,n);
	
	while(m--)
	{
		int oper;
		scanf("%d",&oper);
		if(oper==1)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			cout<<query(1,1,n, l,r)<<endl;
		}
		else if(oper==2)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			update1(1,1,n, l,r,x);
		}
		else
		{
			int k,x;
			scanf("%d%d",&k,&x);
			update2(1,1,n, k,x);
		}
	}
	return 0;
}