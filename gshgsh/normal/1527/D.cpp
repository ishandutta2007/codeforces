#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define pb push_back
#define MAXN 300001
int T,N,siz[MAXN],fa[MAXN];ll ans[MAXN];bool vis[MAXN];vector<int>E[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void dfs(int u,int f){fa[u]=f;siz[u]=1;for(auto v:E[u])if(v!=f)dfs(v,u),siz[u]+=siz[v];}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,0,N+1)ans[i]=vis[i]=siz[i]=0,E[i].clear();For(i,1,N-1){int u=get(),v=get();E[u].pb(v),E[v].pb(u);}dfs(0,0);
		ans[1]=ans[0]=1ll*N*(N-1)/2;for(auto v:E[0])ans[1]-=1ll*siz[v]*(siz[v]-1)/2;int l=0,r=0;vis[0]=1;
		For(i,1,N-1){if(!vis[i]){int x=i,p=i;while(!vis[x])vis[x]=1,p=x,x=fa[x];if(x==l)siz[l]-=siz[p],l=i;else if(x==r)siz[r]-=siz[p],r=i;else break;}ans[i+1]=1ll*siz[l]*siz[r];}
		For(i,0,N)cout<<ans[i]-ans[i+1]<<" \n"[i==N];
	}
	return 0;
}