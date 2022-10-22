#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 300001
#define MAXM 20000001
#define K 1000000000
int N,M,a[MAXN],rt,tot,ls[MAXM],rs[MAXM],mx[MAXM],c[MAXN],ans[MAXN];vector<pair<int,int>>q[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void upd(int&k,int l,int r,int x,int v){if(!k)k=++tot;l!=r?x<=R?upd(ls[k],l,R,x,v):upd(rs[k],L,r,x,v),mx[k]=max(mx[ls[k]],mx[rs[k]]):mx[k]=v;}
int ask(int k,int l,int r,int x,int y){if(!k||x>y)return 0;if(l>=x&&r<=y)return mx[k];int ans=0;x<=R&&(ans=max(ans,ask(ls[k],l,R,x,y))),y>=L&&(ans=max(ans,ask(rs[k],L,r,x,y)));return ans;}
void upd(int x,int v){for(int i=x;i;i-=lowbit(i))c[i]=min(c[i],v);}int ask(int x){int ans=K;for(int i=x;i<=N;i+=lowbit(i))ans=min(ans,c[i]);return ans;}
void solve()
{
	For(i,1,N)c[i]=K;For(i,1,tot)ls[i]=rs[i]=mx[i]=0;tot=rt=0;
	For(i,1,N)
	{
		int j=ask(rt,0,K,a[i],K);while(j){upd(j,a[j]-a[i]);j=ask(rt,0,K,a[i],a[i]+(a[j]-a[i]+1>>1)-1);}
		upd(rt,0,K,a[i],i);for(auto k:q[i])ans[k.second]=min(ans[k.second],ask(k.first));
	}
}
int main()
{
	N=get();For(i,1,N)a[i]=get();M=get();For(i,1,M){int l=get(),r=get();q[r].push_back({l,i});}
	For(i,1,M)ans[i]=K;solve();For(i,1,N)a[i]=K-a[i];solve();For(i,1,M)cout<<ans[i]<<'\n';return 0;
}