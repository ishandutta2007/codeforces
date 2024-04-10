#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define R (l+r>>1)
#define L (l+r>>1)+1
#define INF 0x4000000000000
#define MAXN 100001
int N,M,a[MAXN],rt,tot,cnt[MAXN*100],ls[MAXN*100],rs[MAXN*100];ll sum[MAXN*100]; 
ll get(){ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void upd(int&k,ll l,ll r,int x,int v){if(!k)k=++tot;cnt[k]+=v,sum[k]+=x*v;l!=r?x<=R?upd(ls[k],l,R,x,v):upd(rs[k],L,r,x,v),0:0;}
ll ask1(int k,ll l,ll r,ll x,ll y){return k&&l<=y&&r>=x?l<x||r>y?ask1(ls[k],l,R,x,y)+ask1(rs[k],L,r,x,y):sum[k]:0;}
int ask2(int k,ll l,ll r,ll x,ll y){return k&&l<=y&&r>=x?l<x||r>y?ask2(ls[k],l,R,x,y)+ask2(rs[k],L,r,x,y):cnt[k]:0;}
double Ask(ll v){if(N==1)return v+a[1];double l=0,r=INF;For(i,1,80){double mid=(l+r)/2;ask2(rt,0,INF,0,mid)*mid-ask1(rt,0,INF,0,mid)>=v?r=mid:l=mid;}return l;}
int main()
{
	N=get(),M=get();For(i,1,N)upd(rt,0,INF,a[i]=get(),1);
	For(i,1,M){int opt=get();if(opt&1){int x=get(),v=get();upd(rt,0,INF,a[x],-1),upd(rt,0,INF,a[x]=v,1);}else printf("%.6lf\n",Ask(get()));}return 0;
}