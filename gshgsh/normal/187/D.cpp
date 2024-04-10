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
#define INF 2147483647
#define MAXN 300001
#define MAXM 10000001
int N,M,x,y,a[MAXN],rt,tot,ls[MAXM],rs[MAXM],mn[MAXM];ll s[MAXN],f[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void upd(int&k,int l,int r,int x,int v){if(!k)k=++tot,mn[k]=INF;l!=r?x<=R?upd(ls[k],l,R,x,v):upd(rs[k],L,r,x,v),mn[k]=min(mn[ls[k]],mn[rs[k]]):mn[k]=min(mn[k],v);}
int ask(int k,int l,int r,int x,int y){return k&&l<=y&&r>=x?l<x||r>y?min(ask(ls[k],l,R,x,y),ask(rs[k],L,r,x,y)):mn[k]:INF;}
int Ask(int p){int a=(p+x)%(x+y),b=(p+x+y-1)%(x+y);if(a<=b)return ask(rt,0,x+y-1,a,b);return min(ask(rt,0,x+y-1,a,x+y-1),ask(rt,0,x+y-1,0,b));}
void clear(int&k,int l,int r){if(k)clear(ls[k],l,R),clear(rs[k],L,r),k=0;}
int main()
{
	N=get(),x=get(),y=get();For(i,1,N+1)a[i]=get(),s[i]=s[i-1]+a[i];mn[0]=INF;
	ll sum=0;FOR(i,N,1){sum+=a[i+1];int tmp=Ask((x+y-sum%(x+y))%(x+y));if(tmp==INF)f[i]=sum;else f[i]=f[tmp]+(s[tmp]-s[i]+x+y-1)/(x+y)*(x+y);upd(rt,0,x+y-1,(x+y-sum%(x+y))%(x+y),i);}
	clear(rt,0,x+y-1);tot=0;sum=0;For(i,1,N)sum=(sum+a[i])%(x+y),upd(rt,0,x+y-1,sum,i);
	M=get();For(i,1,M){int t=get();int tmp=Ask((x+y-t%(x+y))%(x+y));if(tmp==INF)cout<<t+s[N+1]<<'\n';else{ll ans=f[tmp]+(s[tmp]+t+x+y-1)/(x+y)*(x+y);cout<<ans<<'\n';}}return 0;
}