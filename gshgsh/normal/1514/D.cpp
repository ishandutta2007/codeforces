#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 300001
int N,M,a[MAXN],rt[MAXN],tot,sum[MAXN*100],ls[MAXN*100],rs[MAXN*100];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int upd(int u,int l,int r,int x,int v){int k=++tot;sum[k]=sum[u],ls[k]=ls[u],rs[k]=rs[u];l!=r?x<=R?ls[k]=upd(ls[k],l,R,x,v):rs[k]=upd(rs[k],L,r,x,v):0;sum[k]+=v;return k;}
int ask(int a,int b,int l,int r,int v){if(l!=r){if(sum[a]-sum[b]<=v)return 0;int x;if(sum[ls[a]]-sum[ls[b]]>v&&(x=ask(ls[a],ls[b],l,R,v)))return x;if(sum[rs[a]]-sum[rs[b]]>v&&(x=ask(rs[a],rs[b],L,r,v)))return x;return 0;}return sum[a]-sum[b]>v?sum[a]-sum[b]:0;}
int main()
{
	N=get(),M=get();For(i,1,N)rt[i]=upd(rt[i-1],1,N,a[i]=get(),1);
	For(i,1,M){int l=get(),r=get(),x=ask(rt[r],rt[l-1],1,N,(r-l+1+1)/2);if(x<=(r-l+1+1)/2){cout<<1<<endl;continue;}int cnt=r-l+1-x;cout<<x-cnt<<endl;}
}