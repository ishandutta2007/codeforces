#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 1000001
int N,M,a[MAXN],tot,rt,dep[MAXN],ls[MAXN],rs[MAXN],tg[MAXN];ll sum[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void build(int dp,int&k,int l,int r){k=++tot;dep[k]=dp;if(dp)build(dp-1,ls[k],l,R),build(dp-1,rs[k],L,r),sum[k]=sum[ls[k]]+sum[rs[k]];else sum[k]=a[l];}
void pt(int k,int v){tg[k]^=v;}
void dwn(int k){if((tg[k]>>dep[k])&1)swap(ls[k],rs[k]),tg[k]^=1<<dep[k];pt(ls[k],tg[k]),pt(rs[k],tg[k]),tg[k]=0;}
void upd(int k,int l,int r,int x,int v){l!=r?dwn(k),x<=R?upd(ls[k],l,R,x,v):upd(rs[k],L,r,x,v),sum[k]=sum[ls[k]]+sum[rs[k]]:sum[k]=v;}
ll ask(int k,int l,int r,int x,int y){return l<=y&&r>=x?l<x||r>y?dwn(k),ask(ls[k],l,R,x,y)+ask(rs[k],L,r,x,y):sum[k]:0;}
int main()
{
	N=get(),M=get();For(i,1,(1<<N))a[i]=get();build(N,rt,1,1<<N);
	For(i,1,M){int opt=get();if(opt==1){int x=get(),v=get();upd(1,1,1<<N,x,v);}else if(opt==2)tg[1]^=(1<<get()+1)-1;else if(opt==3)tg[1]^=1<<get()+1;else{int l=get(),r=get();cout<<ask(1,1,1<<N,l,r)<<'\n';}}return 0;
}