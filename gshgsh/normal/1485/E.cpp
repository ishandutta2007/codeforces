#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,K,dep[MAXN],fa[MAXN],a[MAXN];ll f[MAXN];vector<int>E[MAXN],id[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u,int f){K=max(K,dep[u]=dep[f]+1),fa[u]=f;id[dep[u]].push_back(u);for(auto v:E[u])if(v!=f)dfs(v,u);}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)E[i].clear(),f[i]=0;For(i,2,N){int x=get();E[i].push_back(x),E[x].push_back(i);}For(i,2,N)a[i]=get();
		K=0;For(i,1,N)id[i].clear();dfs(1,0);
		For(i,2,K)
		{
			int mn=1e9,mx=0;ll mx1=0,mx2=-1e9;
			for(auto j:id[i])mn=min(mn,a[j]),mx=max(mx,a[j]),mx1=max(mx1,f[fa[j]]+a[j]),mx2=max(mx2,f[fa[j]]-a[j]);
			for(auto j:id[i])f[j]=max(f[fa[j]]+max(mx-a[j],a[j]-mn),max(mx1-a[j],mx2+a[j]));
		}
		ll ans=0;for(auto i:id[K])ans=max(ans,f[i]);cout<<ans<<'\n';
	}
}