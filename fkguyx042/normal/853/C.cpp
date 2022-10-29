#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 8000005

#define ls tree[t].l
#define rs tree[t].r
#define Ls tree[t1].l
#define Rs tree[t1].r
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,root[N],tot,q,x[N],y[N],T[N],l,d,r,u;

struct Node{
		int sum,l,r;
}tree[M];

void update(int ll,int l,int r,int t,int t1)
{
		tree[t].sum++;
		if (l==r) return;
		else 
		{
				if (ll<=mid)
				{
						ls=++tot;
						tree[ls]=tree[Ls];
						update(ll,l,mid,ls,Ls);
				}
				else 
				{
						rs=++tot;
						tree[rs]=tree[Rs];
						update(ll,mid+1,r,rs,Rs);
				}
		}
}

int ask(int ll,int rr,int l,int r,int t,int t1)
{
		if (ll>rr) return 0;
		if (ll<=l&&r<=rr) return tree[t].sum-tree[t1].sum;
		else
		{
				int S=0;
				if (ll<=mid) S+=ask(ll,rr,l,mid,ls,Ls);
				if (rr>mid)	 S+=ask(ll,rr,mid+1,r,rs,Rs);
				return S;
		}
}

long long work(int x)
{
		return 1ll*x*(x-1)/2;
}

int main()
{
		scanf("%d%d",&n,&q);
		for (i=1;i<=n;++i) scanf("%d",&T[i]);
		for (i=1;i<=n;++i) 
		{
				root[i]=++tot;
				tree[root[i]]=tree[root[i-1]];
				update(T[i],1,n,root[i],root[i-1]);
		}
		long long ans;
		for (i=1;i<=q;++i)
		{
			 scanf("%d%d%d%d",&l,&d,&r,&u);
			 ans=work(n);
			 ans-=work(ask(1,d-1,1,n,root[n],root[0]));
			 ans-=work(ask(u+1,n,1,n,root[n],root[0]));
			 ans-=work(ask(1,n,1,n,root[l-1],root[0]));
			 ans-=work(ask(1,n,1,n,root[n],root[r]));
			 ans+=work(ask(1,d-1,1,n,root[l-1],root[0]));
			 ans+=work(ask(1,d-1,1,n,root[n],root[r]));
			 ans+=work(ask(u+1,n,1,n,root[n],root[r]));
			 ans+=work(ask(u+1,n,1,n,root[l-1],root[0]));
			 printf("%I64d\n",ans);
		}
}