#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 220001
int N,M,a[MAXN],rt,tot,ls[MAXN],rs[MAXN],na[MAXN],nb[MAXN],nc[MAXN],nab[MAXN],nbc[MAXN],nabc[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getc(){char c=getchar();while(c<'a'||c>'c')c=getchar();return c-'a';}
void pushup(int k)
{
	na[k]=na[ls[k]]+na[rs[k]];nb[k]=nb[ls[k]]+nb[rs[k]];nc[k]=nc[ls[k]]+nc[rs[k]];
	nab[k]=min(na[ls[k]]+nab[rs[k]],nab[ls[k]]+nb[rs[k]]);
	nbc[k]=min(nb[ls[k]]+nbc[rs[k]],nbc[ls[k]]+nc[rs[k]]);
	nabc[k]=min(nab[ls[k]]+nbc[rs[k]],min(nabc[ls[k]]+nc[rs[k]],na[ls[k]]+nabc[rs[k]]));
}
void build(int&k,int l,int r){k=++tot;if(l!=r)build(ls[k],l,R),build(rs[k],L,r),pushup(k);else na[k]=a[l]==0,nb[k]=a[l]==1,nc[k]=a[l]==2;}
void upd(int k,int l,int r,int x,int v){if(l==r){na[k]=v==0,nb[k]=v==1,nc[k]=v==2;return;}if(x<=R)upd(ls[k],l,R,x,v);else upd(rs[k],L,r,x,v);pushup(k);}
int main()
{
	N=get(),M=get();For(i,1,N)a[i]=getc();build(rt,1,N);
	For(i,1,M){int x=get(),v=getc();upd(rt,1,N,x,v);cout<<nabc[rt]<<'\n';}return 0;
}