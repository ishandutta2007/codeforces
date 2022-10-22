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
#define lim 1000000000
#define MAXN 100001
#define MAXM 15000001
int N,K,tot,rt,ls[MAXM],rs[MAXM],sum[MAXM],top,sta[MAXM];ll ans;struct node{int x,r,q;}a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int New(){if(top)return sta[top--];return ++tot;}void clear(int&x){ls[x]=rs[x]=sum[x]=0;sta[++top]=x;x=0;}
void upd(int&k,int l,int r,int x,int v){if(!k)k=New();l!=r?x<=R?upd(ls[k],l,R,x,v):upd(rs[k],L,r,x,v),0:0;sum[k]+=v;if(!sum[k])clear(k);}
int ask(int k,int l,int r,int x,int y){return k&&l<=y&&r>=x?l<x||r>y?ask(ls[k],l,R,x,y)+ask(rs[k],L,r,x,y):sum[k]:0;}
void solve(int l,int r)
{
	if(l==r)return;int mid=l+r>>1;solve(l,mid);solve(mid+1,r);
	sort(a+l,a+mid+1,[](node a,node b){return a.q<b.q;});sort(a+mid+1,a+r+1,[](node a,node b){return a.q<b.q;});
	int x=mid+1,y=mid;For(i,l,mid){while(y<r&&a[i].q+K>=a[y+1].q)upd(rt,0,lim,a[++y].x,1);while(x<=y&&a[i].q-K>a[x].q)upd(rt,0,lim,a[x++].x,-1);ans+=ask(rt,0,lim,max(a[i].x-a[i].r,0),min(a[i].x+a[i].r,lim));}
	while(x<=y)upd(rt,0,lim,a[x++].x,-1);
}
int main()
{
	N=get(),K=get();For(i,1,N)a[i].x=get(),a[i].r=get(),a[i].q=get();
	sort(a+1,a+N+1,[](node a,node b){return a.r<b.r;});solve(1,N);cout<<ans<<'\n';return 0;
}