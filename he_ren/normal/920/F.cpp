#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxa = 1e6 + 5;
const int MAXA = maxa + 5;
const int MAXN = 3e5 + 5;

inline int max(int a,int b){ return a>b? a: b;}

bool isnp[MAXA];
int p[MAXA],pcnt=0, f[MAXA];
void f_init(void)
{
	isnp[0]=isnp[1]=1;
	for(int i=2; i<=maxa; ++i)
	{
		if(!isnp[i])
			p[++pcnt]=i, f[i]=i;
		
		for(int j=1; j<=pcnt; ++j)
		{
			if((ll)i*p[j] > maxa) break;
			int tmp=i*p[j];
			isnp[tmp] = 1;
			f[tmp] = p[j];
			if(i%p[j]==0) break;
		}
	}
}

int g[MAXA];
int gao_g(int x)
{
	int res=1;
	while(x>1)
	{
		int cnt=0, t=x;
		while(t%f[x]==0)
			t/=f[x], ++cnt;
		res *= cnt+1;
		x=t;
	}
	return res;
}

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

void update(int u,int l,int r, int ql,int qr)
{
	if(mx[u]<=2) return;
	if(l==r)
	{
		sum[u] = mx[u] = g[mx[u]];
		return;
	}
	int mid = (l+r)>>1;
	if(ql<=mid) update(ls(u),l,mid, ql,qr);
	if(mid<qr) update(rs(u),mid+1,r, ql,qr);
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

int main(void)
{
	f_init();
	for(int i=1; i<maxa; ++i) g[i]=gao_g(i);
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	build(1,1,n);
	while(m--)
	{
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		if(t==1) update(1,1,n, l,r);
		else cout<<query(1,1,n, l,r)<<endl;
	}
	return 0;
}